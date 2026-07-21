class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        // code here
        unordered_set<int> set;
        
        for(int ele: arr) set.insert(ele);
        
        int cnt = 0;
        int ans = 0;
        
        for(int i=0; i<arr.size(); i++){
            if(set.find(arr[i]-1) != set.end()) continue;
            
            else{
                int temp = arr[i];
                while(set.find(temp) != set.end()){
                    cnt++;
                    temp = temp+1;
                    // cout << temp<< " " << cnt<< endl;
                }
                ans = max(ans,cnt);
                cnt=0;
            }
        }
        
        return ans;
    }
};