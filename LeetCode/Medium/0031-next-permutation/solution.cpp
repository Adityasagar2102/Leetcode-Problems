class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int mn= INT_MAX;
        // bool found = false;
        int ind = -1;


        for(int i=n-1; i>0; i--){
            // mn = min(mn,nums[i]);
            if(nums[i]>nums[i-1]){
                // found = true;
                ind = i;
                break;
            }
        }
        if(ind == -1){
            sort(nums.begin(),nums.end());
            return;
        }
        int j=-1;
        int ele = INT_MAX;
        for(int i=ind; i<n; i++ ){
            if(nums[ind-1] < nums[i] && nums[i] < ele){
                ele = nums[i];
                j=i;
            }
        }
        swap(nums[j],nums[ind-1]);
        sort(nums.begin()+ind,nums.end());

        return;

    }
};