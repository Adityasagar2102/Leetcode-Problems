class Solution {
public:

// the important part of this question is removing the cost of the cuts which is cuts[j+1] - cuts[i-1];

    vector<vector<int>> dp;
    int solve(vector<int>&cuts, int i, int j){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mn = 1e9;
        for(int k=i; k<=j; k++){
            int temp = solve(cuts,i,k-1) + solve(cuts,k+1,j) + cuts[j+1] - cuts[i-1] ;
            mn = min(mn,temp);
        }
        return dp[i][j] = mn;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();

        dp.resize(m, vector<int>(m, -1));
        return solve(cuts,1,cuts.size()-2);
    }
};