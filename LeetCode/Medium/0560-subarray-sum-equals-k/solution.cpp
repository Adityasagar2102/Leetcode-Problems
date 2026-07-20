class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        // vector<int>presum;

        int sum =0;
        int cnt = 0;
        mp[0]=1;
        
        for(int num: nums){
            sum += num;
            if(mp.find(sum-k)!= mp.end()){
                cnt += mp[sum-k];
            }
            mp[sum]++;

            // ans.push_b/ack(sum);
        }

        return cnt;

    }
};