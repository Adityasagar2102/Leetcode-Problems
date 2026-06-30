class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& prices, int buy, int ind,int fee){
        if(ind == prices.size()) return 0;
        int profit = 0;
        if(dp[buy][ind]!= -1) return dp[buy][ind];

        if(buy){ // stock is bought
            profit = max(prices[ind] + solve(prices,0,ind+1,fee),solve(prices,1,ind+1,fee));
        }else{
            profit = max(solve(prices,1,ind+1,fee) -prices[ind]-fee, solve(prices,0,ind+1,fee));
        }

        return dp[buy][ind] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp.assign(3,vector<int>(n+1,-1));
        return solve(prices,0,0,fee);
    }
};