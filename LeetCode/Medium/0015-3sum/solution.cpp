class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(),nums.end());

        map<int,int> mp; // nums,index
        // for(int i=0; i<n; i++) 

        set<vector<int>> ansmid;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(i==j) continue;
                int temp = -(nums[i] + nums[j]);
                if(mp.find(temp)!= mp.end()){
                    if(i==mp[temp] || j==mp[temp]) continue;
                    vector<int> arr = {nums[i],nums[j],temp};
                    sort(arr.begin(),arr.end());
                    ansmid.insert(arr);
                }
            }
            mp[nums[i]] = i;
        }

        vector<vector<int>> ans(ansmid.begin(), ansmid.end());
        

        return ans;
    }
};