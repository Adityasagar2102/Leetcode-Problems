class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        // s - sn --> x-y
        // s2 - s2n --> x2-y2

        long long sn = (n*(n+1))/2;
        long long s =0;
        long long s2n = (n*(n+1)*(2*n +1))/6;
        long long s2 =0;

        for(auto num: nums){
            s += num;
            s2 += 1LL*num*num;
        }

        // cout <<s2<<" "<<s2n<<endl;
        long long val1 = s - sn; // x-y
        long long val2 = s2 - s2n;
        val2 = val2/val1; // x+y

        // cout <<val1<<" "<<val2<<endl;

        long long x = (val1+val2)/2;
        long long y = val2-x;

        return {(int)x,(int)y};
    }
};