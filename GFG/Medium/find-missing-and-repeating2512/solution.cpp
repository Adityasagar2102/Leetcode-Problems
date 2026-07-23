class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n = arr.size();
        long long s = (n*(n+1))/2;
        long long s2 = (n*(n+1)*(2*n+1))/6;
        
        long long sn=0;
        long long s2n=0;
        
        for(int ele: arr){
            sn += ele;
            s2n += 1LL*ele*ele;
        }
        
        // x-y
        long long val1 = s-sn;
        long long val2 = s2-s2n;
        
        // x+y
        val2 = val2/val1;
        
        long long x = (val1+val2)/2 ;
        long long y = val2-x;
        
        return {(int)y,(int)x};
    }
};