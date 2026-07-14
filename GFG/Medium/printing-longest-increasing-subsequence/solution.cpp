class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n+1,1), hash(n);
        
        int lis = 1;
        int lastIndex=0;
        
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int prev= 0; prev<i; prev++){
                if(arr[i]>arr[prev] && dp[prev]+1>dp[i]){
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if(dp[i] > lis){
                lis = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int>temp;
        temp.push_back(arr[lastIndex]);
        
        
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        
        reverse(temp.begin(), temp.end());
        
        return temp;
        
    }
};