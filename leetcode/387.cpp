class Solution {
public:
    int firstUniqChar(const std::string& s) {
        std::unordered_map<char, int> umap;
        int idx = -1;

        for (char c : s) {
            umap[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (umap[s[i]] == 1) {
                return i; 
            }
        }

        return -1;
    }
};
