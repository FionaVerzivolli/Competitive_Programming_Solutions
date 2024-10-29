class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int total = 0;
        
        for(int i = 0; i < k; i++){
            total += nums[i];
        }
        
        int maxSum = total; 

        for(int i = k; i < nums.size(); i++){
            total = total + nums[i] - nums[i - k]; 
            maxSum = max(maxSum, total); 
        }
        
        return (double) maxSum / k;  
    }
};
