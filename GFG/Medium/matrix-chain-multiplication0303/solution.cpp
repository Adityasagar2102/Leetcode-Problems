class Solution {
  public:
    vector<vector<int>>dp;
    int solve(vector<int>&arr, int i ,int j){
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int mn = INT_MAX;
        
        for(int k=i; k<j; k++){
            int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
            mn = min(mn,temp);
        }
        
        return dp[i][j] = mn;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(arr,1,n-1);
        
    }
};