class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj =0;
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(cnt==0){
                maj = nums[i];
            }
            if(maj == nums[i]){
                cnt++;
                // cout << cnt<< endl;
            }
            else cnt--;
        }

        return maj;
    }
};