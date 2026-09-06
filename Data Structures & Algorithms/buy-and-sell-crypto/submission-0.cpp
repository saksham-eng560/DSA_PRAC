class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = INT_MIN;
       int maxi = 0;
       for(int i = prices.size()-1;i>=0;i--) {
        int buy = prices[i];
        maxi = max(prices[i],maxi);
        profit = max(profit,maxi-buy);
       } 
       return profit;
    }
};