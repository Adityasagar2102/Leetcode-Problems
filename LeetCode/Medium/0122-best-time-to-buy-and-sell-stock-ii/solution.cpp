class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& prices, bool buy, int ind){
        if(ind == prices.size()) return 0;
        int stockbuy = 0;
        int stocksell = 0;
        if(dp[buy][ind]!= -1) return dp[buy][ind];

        if(buy){ // stock is bought
            stockbuy = max(prices[ind] + solve(prices,false,ind+1),solve(prices,true,ind+1));
        }else{
            stocksell = max(solve(prices,true,ind+1) -prices[ind], solve(prices,false,ind+1));
        }

        return dp[buy][ind] = max(stocksell,stockbuy);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // int profit = 0;

        // for(int i=0; i<n-1; i++){
        //     if(prices[i+1]> prices[i]) profit += (prices[i+1]-prices[i]);
        // }

        // return profit;
        dp.assign(3,vector<int>(n+1,-1));
        return solve(prices,false,0);
    }
};