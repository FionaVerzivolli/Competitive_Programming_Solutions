class Solution {
public:
    void sortColors(vector<int>& nums) {

        for (int i = 1; i < nums.size(); ++i) {
           int j = i;
           while(j > 0 && nums[j - 1] > nums[j]){
                int a = nums[j - 1];
                nums[j-1] = nums[j];
                nums[j] = a;
                j--;
           }
        }
    }
};
