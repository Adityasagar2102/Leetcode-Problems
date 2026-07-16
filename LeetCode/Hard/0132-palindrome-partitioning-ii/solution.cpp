class Solution {
public:
    bool check(string&s, int i, int j){
        if(dpcheck[i][j]!=-1) return dpcheck[i][j];
        int a = i;
        int b = j;
        while(a<b){
            if(s[a]==s[b]){
                a++;
                b--;
            }else{
                return dpcheck[i][j] = false;
            }
        }
        return dpcheck[i][j] = true;
    }
    // vector<vector<int>>dp;
    vector<int>dp;
    vector<vector<int>>dpcheck;
    // int solve(string &s, int i, int j){
    //     if(i==j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(check(s,i,j)) return dp[i][j] = 0;

    //     int numberofcut = 1e9;
    //     for(int k=i+1; k<=j; k++){
    //         int temp = solve(s,i,k-1) + solve(s,k,j) + 1;
    //         // cout << temp<<endl;
    //         numberofcut = min(numberofcut,temp);
    //     }

    //     return dp[i][j] = numberofcut;
    // }
    int solve(string&s, int i){
        if(i==s.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 1e9;

        for(int j=i; j<s.size();j++){
            if(check(s,i,j)){
                if(j==s.size()-1) return dp[i] = 0;
                ans = min(ans,1+solve(s,j+1));
                // else ans 
            }
        }

        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        // dp.resize(n+1,vector<int>(n+1,-1));
        dpcheck.resize(n+1,vector<int>(n+1,-1));
        dp.resize(n+1,-1);
        // if(check(s,0,n-1)) return 0;
        return solve(s,0);
    }
};