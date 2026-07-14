class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n+1,1);
        vector<int>count(n+1,1);
        int lis = 1;
        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[i]>nums[prev]){
                    // lis = max(dp[i],dp[prev]+1);
                    if(dp[prev]+1 > dp[i]){
                        // lis = dp[i];
                        dp[i] = dp[prev]+1;
                        count[i] = count[prev];
                    }else if(dp[prev]+1==dp[i]){
                        count[i] += count[prev];
                    }
                    lis = max(lis,dp[i]);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(dp[i] == lis){
                cnt += count[i];
            }
        }

        return cnt;
    }
};