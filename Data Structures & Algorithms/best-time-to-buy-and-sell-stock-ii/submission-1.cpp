class Solution {
private:
    int f(int i,int holding,vector<int> &prices,vector<vector<int>> &dp) {
        if(i == prices.size()) return 0;
        if(dp[i][holding] != -1) return dp[i][holding];

        int profit;
        if(holding == 0){
            profit = max(-prices[i] + f(i+1,1,prices,dp),f(i+1,0,prices,dp));
        } else {
            profit = max(prices[i] + f(i+1,0,prices,dp),f(i+1,1,prices,dp));
        }

        return dp[i][holding] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return f(0,0,prices,dp);
    }
};