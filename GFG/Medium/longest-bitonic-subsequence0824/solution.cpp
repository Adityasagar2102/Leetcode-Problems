class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        int lis= 0;
        vector<int>dp(n,1);
        vector<int>decdp(n,1);
        
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i],dp[prev]+1);
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            for(int prev=n-1; prev>i; prev--){
                if(nums[prev] < nums[i]){
                    decdp[i] = max(decdp[i],decdp[prev]+1);
                }
            }
        }
        
        for(int i=1; i<n-1; i++){
            // cout<<dp[i] <<" "<<decdp[i]<< "  "<<i<<endl;
            if(dp[i]-1 && decdp[i]-1)lis = max(lis,dp[i]+decdp[i]-1);
        }
        
        return lis;
        
    }
};
