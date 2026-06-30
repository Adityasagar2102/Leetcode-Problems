class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(vector<int>& prices, int ind, int buy, int t){
        if(ind==prices.size()) return 0;
        if(t==0) return 0;

        int profit = 0;
        if(dp[ind][buy][t]!= -1) return dp[ind][buy][t];

        if(buy){
            profit = max(solve(prices,ind+1,0,t)-prices[ind], solve(prices,ind+1,1,t));
        }else{
            profit = max(solve(prices,ind+1,1,t-1)+prices[ind], solve(prices,ind+1,0,t));
        }

        return dp[ind][buy][t] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        dp.assign(prices.size() +1, vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,k);
    
    }
};