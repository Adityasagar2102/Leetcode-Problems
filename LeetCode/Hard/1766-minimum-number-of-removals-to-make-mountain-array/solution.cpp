class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>front(n,1);
        vector<int>back(n,1);

        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[i]>nums[prev]){
                    front[i] = max(front[i],front[prev]+1);
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            for(int prev=n-1; prev>i; prev--){
                if(nums[i]>nums[prev]){
                    back[i] = max(back[i],back[prev]+1);
                }
            }
        }
        int lis = 0;
        for(int i=1; i<n-1; i++){
            if(front[i]-1 && back[i]-1)lis = max(lis, back[i]+front[i]-1);
        }

        return n-lis;

    }
};