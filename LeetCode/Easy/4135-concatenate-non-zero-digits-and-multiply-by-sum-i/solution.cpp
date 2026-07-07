class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long temp = n;
        vector<int> nums;
        while(temp >0){
            long long unit = temp%10;
            temp = temp/10;
            sum += unit;
            if(unit!=0) nums.push_back(unit);
        }
        long long  ans = 0;
        for(int i=nums.size()-1; i>=0; i--){
            ans *=10;
            ans += nums[i];
        }

        return ans*sum*1LL;
    }
};