class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long long n = nums.size();
        sort(nums.begin(), nums.end());
        long long l,r;

        vector<vector<int>> ans;

        for(long long i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            // if(i!=0 && nums[i]==nums[i-1])i--;
            for(long long j=i+1; j<n; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                l=j+1;
                r=n-1;
                while(l<r){
                    long long sum = 1LL*nums[i]+1LL*nums[l]+1LL*nums[r]+1LL*nums[j];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r && nums[l]==nums[l+1])l++;
                        while(l<r && nums[r]==nums[r-1])r--;
                        l++;
                        r--;
                    }
                    if(sum<target){
                        while(l<r && nums[l]==nums[l+1])l++;
                        l++;
                    }
                    if(sum>target){
                        while(l<r && nums[r]==nums[r-1])r--;
                        r--;
                    }
                }
                // if(nums[j]==nums[])
                
            }
        }

        return ans;
    }
};