class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int ind,int sum){
        if(ind==nums.size()){
            return sum==0;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];

        int nottake = solve(nums,ind+1,sum);
        int take = 0;
        if(sum - nums[ind] >=0){
            take = solve(nums,ind+1,sum-nums[ind]);
        }

        return dp[ind][sum] = take+nottake;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = 0;
        for(int num: nums) totalsum+=num;
        int t = totalsum - target;
        if(t<0 || t%2!=0) return 0;

        dp.assign(n+1,vector<int>(t/2 +1,-1));
        return solve(nums,0,t/2);
    }
};