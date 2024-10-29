class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp = {0, 0};
        int size = 2;
        for(int i = 2; i <= cost.size(); i++){
            dp.push_back(min(cost[i -2] + dp[i-2], cost[i - 1] + dp[i-1]));
            size++;
        }


        return dp[cost.size()];
    }
};
