class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int high = n-1;
        int mid;

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            mid = i+1;
            high = n-1;
            while(mid<high){
                int sum = nums[i]+nums[mid]+nums[high];
                if(sum==0){
                    ans.push_back({nums[i],nums[mid],nums[high]});
                    int mtemp = nums[mid];
                    int htemp = nums[high];
                    while(mid<high && nums[mid]==mtemp) mid++;
                    while(high>mid && nums[high]==htemp) high--;
                }
                else if(sum<0){
                    int mtemp = nums[mid];
                    while(mid<high && nums[mid]==mtemp) mid++;
                }
                else{
                    int htemp = nums[high];
                    while(high>mid && nums[high]==htemp) high--;
                }
            }
            int tempi = nums[i];
            while(i<n && nums[i]==tempi) i++;
            i--;
        }

        return ans;
    }
};