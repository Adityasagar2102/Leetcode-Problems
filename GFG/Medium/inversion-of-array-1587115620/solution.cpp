class Solution {
  public:
    int SortandCount(vector<int> &arr,int low,int high){
        if(low==high)return 0;
        
        int mid = (low+high)/2;
        
        int left = SortandCount(arr,low,mid);
        int right = SortandCount(arr,mid+1,high);
        int across = MergeandCount(arr,low,mid,high);
        
        return left+right+across;
    }
    int MergeandCount(vector<int>&arr,int low,int mid,int high){
        vector<int> mergearr;
        
        int i = low;
        int j = mid+1;
        int cnt = 0;
        
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                mergearr.push_back(arr[i]);
                i++;
            }
            else{
                mergearr.push_back(arr[j]);
                j++;
                cnt = cnt+ (mid-i+1);
            }
        }
        while(i<=mid){
            mergearr.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            mergearr.push_back(arr[j]);
            j++;
        }
        j=0;
        for(int i=low; i<=high; i++){
            arr[i] = mergearr[j++];
        }
        
        return cnt;
    }
    
    int inversionCount(vector<int> &arr) {
        // code here
        int n = arr.size();
        int inversions = SortandCount(arr,0,n-1);
        
        return inversions;
        
    }
};