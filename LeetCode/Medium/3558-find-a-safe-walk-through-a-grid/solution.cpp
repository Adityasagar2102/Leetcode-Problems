class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        deque<pair<int,pair<int,int>>>dq; //health,r,c

        vector<vector<int>>vis(n,vector<int>(m,0));
        dq.push_front({health-grid[0][0],{0,0}});
        vis[0][0] = 1;

        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};

        while(!dq.empty()){
            int r = dq.front().second.first;
            int c = dq.front().second.second;
            int h = dq.front().first;
            dq.pop_front();
            if(h==0) continue;
            if(r == n-1 && c==m-1) return true;
            

            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && h-grid[nr][nc] >0){
                    vis[nr][nc] = 1;
                    if(grid[nr][nc] == 1){
                        dq.push_back({h-1,{nr,nc}});
                    }else{
                        dq.push_front({h,{nr,nc}});
                    }
                }
            }
        }

        return false;

    }
};