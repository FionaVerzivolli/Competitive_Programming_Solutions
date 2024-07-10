class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // just make two for loops lol.
        std::unordered_map<int, int> NumMap;
        for(int i=0; i < size(nums); i++){
            int complement = target - nums[i];
            if(NumMap.find(complement) != NumMap.end()){
                return {i, NumMap[complement]};
                }
            NumMap[nums[i]] = i;
            }
        return {};
    }
};