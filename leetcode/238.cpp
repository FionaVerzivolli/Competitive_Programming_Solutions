class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        int product1 = 1;
        int product2 = 1;
        vector<int> front;
        vector<int> back;
        vector<int> result;

        for (int i = 0; i < size; i++) {
            product1 *= nums[i];
            product2 *= nums[size - 1 - i];
            front.push_back(product1);
            back.push_back(product2);
        }

        result.push_back(back[size - 2]); 

        for (int i = 1; i < size - 1; i++) {
            result.push_back(front[i - 1] * back[size - i - 2]);
        }

        result.push_back(front[size - 2]); 

        return result;
    }
};
