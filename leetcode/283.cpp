class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int n = nums.size();
        int last = 0; 
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                std::swap(nums[last], nums[i]);
                last++; 
            }
        }
    }
};
