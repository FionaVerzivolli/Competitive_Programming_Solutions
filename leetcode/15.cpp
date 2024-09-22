class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());  

        int n = nums.size();
        std::vector<std::vector<int>> triplets;
        
        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int target = -nums[i];  
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = nums[j] + nums[k];
                
                if (sum == target) {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    
                    j++;
                    k--;
                } else if (sum < target) {
                    j++;  
                } else {
                    k--;  
                }
            }
        }
        
        return triplets;
    }
};
