class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(vector<int>& prices, int ind, int buy, int t){
        if(t==0) return 0;
        if(ind==prices.size()) return 0;

        int profit = 0;
        if(dp[ind][buy][t]!= -1) return dp[ind][buy][t];

        if(buy){
            profit = max(solve(prices,ind+1,false,t)-prices[ind], solve(prices,ind+1,true,t));
        }else{
            profit = max(solve(prices,ind+1,true,t-1)+prices[ind], solve(prices,ind+1,false,t));
        }

        return dp[ind][buy][t] = profit;
    }
    int maxProfit(vector<int>& prices) {
        
        dp.assign(prices.size() +1, vector<vector<int>>(3,vector<int>(3,-1)));
        return solve(prices,0,true,2);
    }
};