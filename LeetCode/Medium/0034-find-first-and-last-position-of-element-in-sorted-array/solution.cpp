class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        if(n==0) return {-1,-1};

        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>=target) high = mid-1;
            else low = mid+1;
        }
        int start = low;
        low = 0;
        high = n-1;

        while(low<=high){
            int mid = low+(high-low)/2;

            if(nums[mid]<=target) low = mid+1;
            else high = mid-1;
        }
        int end = low;

        if(start<n &&nums[start]==target) return {start,end-1};
        return {-1,-1};
    }
};