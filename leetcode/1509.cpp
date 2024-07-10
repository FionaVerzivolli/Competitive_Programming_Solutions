class Solution {
public:
    int minDifference(vector<int>& nums) {
        int size = nums.size();
        if(size <= 3){
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        std::vector<int> mins;

        mins.push_back(nums[size-1] - nums[3]);
        mins.push_back(nums[size-2] - nums[2]);
        mins.push_back(nums[size-4] - nums[0]);
        mins.push_back(nums[size-3] - nums[1]);
        int min = mins[0];
        for(int i = 0; i < mins.size(); ++i){
            if(mins[i] < min){
                min = mins[i];
            }
        }
        return min;
    }
};
