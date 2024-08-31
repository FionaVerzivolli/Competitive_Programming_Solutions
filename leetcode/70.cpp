class Solution {
public:
    std::unordered_map<int, int> cache;
    int climbStairs(int n) {
        // use memoization
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }

        if(cache.find(n) != cache.end()){
            return cache[n];
        }
        int a = climbStairs(n-1) + climbStairs(n-2);
        cache[n] = a;
        return a;
    }
};
