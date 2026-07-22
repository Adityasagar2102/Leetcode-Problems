class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mp;
        
        int sum = 0;
        int len = 0;
        // mp[0]= 0;
        
        for(int i=0; i<n; i++){
            sum+=arr[i];
            int temp = sum;
            if(mp.find(temp)!=mp.end()){
                len = max(len,i - mp[temp]);
                // cout << i << " "<<len<<" " << sum << " "<< mp[temp]<< endl;
                
            }
            if(sum==0){
                len = max(len,i+1);
            }
            
            if(mp.find(sum) == mp.end())mp[sum] = i;
        }
        
        return len;
        
    }
};