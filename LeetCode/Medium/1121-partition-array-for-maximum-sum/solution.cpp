class Solution {
public:
    int dp[501];
    int solve(int i , vector<int> & arr, int k){
        if(i == arr.size())return 0;
        if(dp[i]!=-1) return dp[i];

        int ans = INT_MIN;
        int mx = INT_MIN;
        for(int j = 1; j<=k && i+j <= arr.size(); j++){
            mx = max(mx,arr[i+j-1]);
            ans = max(ans, solve(i+j, arr, k) + mx *(j));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0, arr, k);

    }
};