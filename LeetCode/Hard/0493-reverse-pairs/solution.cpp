class Solution {
public:
    int SortAndCount(vector<int>& nums,int low,int high){
        if(low==high) return 0;
        int mid = (low+high)/2;

        int r1 = SortAndCount(nums,low,mid);
        int r2 = SortAndCount(nums,mid+1,high);
        int r = MergeAndCount(nums,low,mid,high);

        return r1+r2+r;
    }
    int MergeAndCount(vector<int>&nums,int low,int mid,int high){
        vector<int>mergearr;
        int i=low;
        int j=mid+1;
        int InversionCount = 0;

        for(int i=low ;i<=mid; i++){
            while(j<=high && 1LL*nums[i]>2LL*nums[j]) j++;
            InversionCount += (j - mid-1);
        }   

        i=low;
        j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                mergearr.push_back(nums[i]);
                i++;
            }
            else{
                mergearr.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            mergearr.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            mergearr.push_back(nums[j]);
            j++;
        }
        j=0;
        for(int i=low; i<=high; i++){
            nums[i] = mergearr[j++];
        }

        return InversionCount;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        return SortAndCount(nums,0,n-1);
    }
};