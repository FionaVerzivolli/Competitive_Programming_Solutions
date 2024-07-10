class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int> mapping;
        int length = 0;
        bool has_odd = false;
        for (int i = 0; i < s.size(); i++) {
            char key = s[i];
            if (mapping.find(key) != mapping.end()) {
                mapping[key]++;
            } else {
                mapping[key] = 1;
            }
        }
        for (const auto& pair : mapping) {
            if (pair.second % 2 == 0) {
                length += pair.second;
            } else {
               length += pair.second - 1;
               has_odd = true;
            }
        }
        if(has_odd){
            length++;
        }
        return length ;
    }
        
};
