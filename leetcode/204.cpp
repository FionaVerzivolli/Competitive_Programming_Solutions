class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        std::vector<bool> is_prime(n, true);
        
        for (int p = 2; p * p < n; ++p) {
            if (is_prime[p]) {
                for (int i = p * p; i < n; i += p) {
                    is_prime[i] = false;
                }
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) {
                ++count;
            }
        }
        
        return count;
    }
};

