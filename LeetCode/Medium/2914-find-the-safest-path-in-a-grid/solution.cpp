class Solution {
public:
    int distance(vector<pair<int,int>>& thief, int i,int j){
        int dist = INT_MAX;
        // int a = 0,b = 0;
        for(auto t: thief){
            int manhatan = abs(t.first - i) + abs(t.second - j);
            dist = min(manhatan,dist);
        }
        return dist;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;
        priority_queue<pair<int,pair<int,int>>> pq; // dist,i,j;

        vector<pair<int,int>> thief;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) thief.push_back({i,j});
            }
        }

        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0] = 1;
        pq.push({distance(thief,0,0),{0,0}});
        int ans = INT_MAX;
        bool end = false;

        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int celldist = pq.top().first;
            pq.pop();

            ans = min(celldist,ans);
            if(r==n-1 && c==n-1){
                end = true;
                break;
            }
            int dr[4] = {0,0,1,-1};
            int dc[4] = {1,-1,0,0};

            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && vis[nr][nc]==0){
                    int d = distance(thief,nr,nc);
                    pq.push({d,{nr,nc}});
                    vis[nr][nc] = 1;
                }
            }
        }
        if(!end) return 0;
        return ans;
    }
};