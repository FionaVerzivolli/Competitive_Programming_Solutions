class Solution {
public:
    int numTilings(int n) {
        vector<long long> dp = {1, 2, 5};
        for (long long i = 3; i < n; i ++) {
            dp.push_back((2 * dp[i - 1] + dp[i - 3]) % 1000000007);
        }
        return dp[n - 1];
    }
    
};
