class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        int max_number = *std::max_element(nums.begin(), nums.end());
        
        for (int num = 0; num <= max_number; ++num) {
            if (num_set.find(num) == num_set.end()) {
                return num;
            }
        }
        
        return max_number + 1;
    }
};
