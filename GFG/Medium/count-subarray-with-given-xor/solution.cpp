class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mp;
        
        int sumxor = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            sumxor = sumxor^arr[i];
            int temp = sumxor^k;
            if(mp.find(temp) != mp.end()){
                cnt += mp[temp];
            }
            if(sumxor==k) cnt++;
            mp[sumxor]++;
        }
        
        return cnt;
    }
};