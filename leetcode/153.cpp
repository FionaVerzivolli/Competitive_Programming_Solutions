class Solution {
public:
    int findMin(vector<int>& nums) {
        int minIndex = 0;          
        int endIndex = nums.size() - 1; 

        while (minIndex < endIndex) {
            int midIndex = (minIndex + endIndex) / 2; 
            
            if (nums[midIndex] > nums[endIndex]) {
                minIndex = midIndex + 1;
            } else {
                endIndex = midIndex; 
            }
        }
        return nums[minIndex]; 
    }
};
