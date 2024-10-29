class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum_left = 0;
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            total+=nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            if(sum_left == total - sum_left - nums[i]){
                return i;
            }
            sum_left += nums[i];
        }
        return -1;
    }
};
