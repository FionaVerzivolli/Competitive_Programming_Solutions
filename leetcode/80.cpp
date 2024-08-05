class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int x = nums.size();

        for (int i = x - 1; i > 0; --i) {
            if (nums[i] == nums[i - 1]) {
                count++;
                if (count >= 2) {
                    nums.erase(nums.begin() + i);
                    count++;
                    x--;
                }
            } else {
                count = 0;
            }
        }

        return nums.size();
    }
};
