class Solution {
public:
    std::vector<int> memo;
    int rob(vector<int>& nums) {
        int a = nums.size();
        memo.push_back(nums[0]);
        if(a == 1){
            return memo[0];
        }
        if(a == 2){
            return std::max(nums[0], nums[1]);
        }

        memo.push_back(std::max(nums[0], nums[1]));
        int curr_max = memo[1];

        for(int i = 2; i < a; i++){
            int n = std::max((memo[i - 2] + nums[i]), memo[i - 1]);
            memo.push_back(n);
            if(n > curr_max){
                curr_max = n;
            }
        }
        return curr_max;

    }
};
