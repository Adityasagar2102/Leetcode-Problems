class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj = nums[0];
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(maj==nums[i]){
                cnt++;
            }else{
                cnt--;
                cout << cnt<< endl;
            }
            if(cnt<0){
                cnt=0;
                maj=nums[i];
            }
        }

        return maj;
    }
};