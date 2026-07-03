class Solution {
public:
    using ll = long long;
    const ll INF = 4e18;

    bool check(int score,
               vector<vector<pair<int,int>>>& adj,
               vector<bool>& online,
               long long k,
               int n) {

        vector<ll> dist(n, INF);
        priority_queue<pair<ll,int>,
                       vector<pair<ll,int>>,
                       greater<pair<ll,int>>> pq;

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()) {
            auto [d,u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &[v,w] : adj[u]) {

                if(w < score) continue;

                if(v != n-1 && !online[v]) continue;

                if(dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                     vector<bool>& online,
                     long long k){

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);

        int mx = 0;

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            mx = max(mx,w);
        }

        int lo = 0;
        int hi = mx;
        int ans = -1;

        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;

            if(check(mid,adj,online,k,n)) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};


