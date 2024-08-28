class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::unordered_map<int, int> umap; // Fixed declaration of umap

        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(nums[i]) != umap.end()) {
                umap[nums[i]]++;
            } else {
                umap[nums[i]] = 1;
            }
        }

        for (const auto& pair : umap) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        return 0;
    }
};
