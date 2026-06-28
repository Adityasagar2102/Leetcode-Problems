class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string &s, string &p, int i, int j){
        if(i==s.size() && j==p.size()) return true;
        if(i==s.size() || j==p.size()){
            if(p[j] == '*') return solve(s,p,i,j+1);
             return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
    

        if(p[j] == '*'){
            return dp[i][j]= solve(s,p,i+1,j)  || solve(s,p,i,j+1);
        }
        if(p[j] == '?'){
            return dp[i][j] = solve(s,p,i+1,j+1);
        }
        if(p[j] == s[i]){
            return dp[i][j] = solve(s,p,i+1,j+1);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        dp.assign(s.size()+1, vector<int>(p.size()+1, -1));
        // if()
        return solve(s,p,0,0);
    }
};