class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> a;

        for (const auto& str : strs) {
            std::string sortedStr = str; 
            std::sort(sortedStr.begin(), sortedStr.end());

            a[sortedStr].push_back(str);
        }

        std::vector<std::vector<std::string>> ans;
        for (const auto& pair : a) {
            ans.push_back(pair.second); 
        }

        return ans;
    }
};
