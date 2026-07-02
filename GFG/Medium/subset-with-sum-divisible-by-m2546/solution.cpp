class Solution {
  public:
    vector<vector<int>>dp;
    bool solve(vector<int>&arr, int k, int ind, int rem,bool taken){
        if(ind<0){
            return taken && rem%k==0;
        }
        if(taken && dp[ind][rem] != -1)
            return dp[ind][rem];
        
        if(solve(arr,k,ind-1,rem,taken))
            return taken ? dp[ind][rem] = true : true;
        
        if(solve(arr,k,ind-1,(arr[ind] + rem)%k,true))
            return taken ? dp[ind][rem] = true : true;

        if(taken)
            dp[ind][rem] = false;
        // if(take%k == 0 || nottake%k==0) return true;
        return false;
        
    }
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        dp.assign(n,vector<int>(k,-1));
        
        // for(int i=0; i<n; i++){
        //     int sum = 0;
        //     for(int j=i; j<n; j++){
        //         sum += arr[j];
        //         if(sum%k==0) return true;
        //     }
        // }
        
        return solve(arr,k,n-1,0,false);
    }
};