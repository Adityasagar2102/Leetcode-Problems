class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mp;
        
        int mxLen = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(mp.find(sum) == mp.end()) 
                mp[sum] = i;
            int temp = sum-k;
            if(mp.find(temp) != mp.end()){
                mxLen = max(mxLen,i - mp[temp]);
            }
            if(sum==k){
                mxLen = max(mxLen,i+1);
            }
        }
        
        return mxLen;
        
    }
};