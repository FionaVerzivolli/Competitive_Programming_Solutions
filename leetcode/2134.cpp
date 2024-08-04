class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int num_ones = count(nums.begin(), nums.end(), 1);
        int n = nums.size();
        
        if (num_ones == 0 || num_ones == n) {
            return 0; // if there are no ones or all ones, no swaps are needed
        }

        vector<int> extendedNums(nums.begin(), nums.end());
        extendedNums.insert(extendedNums.end(), nums.begin(), nums.end());

        int minSwaps = num_ones;
        int currentZeros = 0;

        for (int i = 0; i < num_ones; ++i) {
            if (extendedNums[i] == 0) {
                ++currentZeros;
            }
        }
        minSwaps = currentZeros;

        for (int i = 1; i < n; ++i) {
            if (extendedNums[i - 1] == 0) {
                --currentZeros;
            }
            if (extendedNums[i + num_ones - 1] == 0) {
                ++currentZeros;
            }
            minSwaps = min(minSwaps, currentZeros);
        }

        return minSwaps;
    }
};
