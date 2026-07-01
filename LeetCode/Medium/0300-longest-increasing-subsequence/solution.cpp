class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int ind, int last){
        if(ind == nums.size()) return 0;
        if(dp[ind][last+1] != -1) return dp[ind][last+1];
        
        int take = 0;
        int nottake = solve(nums,ind+1,last);
        if(last==-1 || nums[ind] > nums[last]){
            take = 1 + solve(nums, ind+1, ind);
        }

        return dp[ind][last+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n+1,vector<int>(n+2,-1));
        return solve(nums,0,-1);
        
    }
};