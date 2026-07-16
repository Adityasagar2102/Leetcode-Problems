class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long n = nums.size();
        vector<int>prefixgcd(n);

        long long mx=0;
        for(int i=0; i<n; i++){
            mx = max(mx,nums[i]*1LL);
            prefixgcd[i] = gcd(mx,nums[i]);
        }

        sort(prefixgcd.begin(),prefixgcd.end());

        long long l=0, h=n-1;
        long long ans=0;

        while(l<h){
            ans += gcd(prefixgcd[l], prefixgcd[h]);
            l++;
            h--;
        }

        return ans;
    }
};