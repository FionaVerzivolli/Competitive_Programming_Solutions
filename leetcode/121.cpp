class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currmin = prices[0];
        int profit = 0;
        
        for(int i = 0; i < prices.size(); i++){
            currmin = min(currmin, prices[i]);
            profit = max(profit, prices[i] - currmin);
        }
        return profit;
    }
};
    
