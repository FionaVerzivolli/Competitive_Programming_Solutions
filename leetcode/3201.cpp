class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int parity = nums[0] % 2, odd = 0, even = 0, both = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                even++;
            } else {
                odd++;
            }
            if (num % 2 == parity) {
                both++;
                parity = 1 - parity; 
            }
        }
        return max(both, max(even, odd));
    }
};
