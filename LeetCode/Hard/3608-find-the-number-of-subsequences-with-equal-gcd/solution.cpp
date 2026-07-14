class Solution {
public:
    int MOD = 1e9+7;
    int dp[201][201][201];
    int solve(vector<int>&nums,int ind, int first,int second){
        if(ind==nums.size()){
            if(first!=0 && second!=0){
                return first==second;
            }else return 0;
        }
        if(dp[ind][first][second] != -1) return dp[ind][first][second];

        int skip = solve(nums,ind+1, first, second);
        int f1 = solve(nums,ind+1, gcd(first,nums[ind]),second);
        int f2 = solve(nums,ind+1,first, gcd(second,nums[ind]));
        return dp[ind][first][second] = (0LL + skip + f1 + f2)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,0);
    }
};