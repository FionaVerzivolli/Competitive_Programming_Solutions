class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return ""; 
        }
        
        std::string prefix = "";
        int array_size = strs.size();
        int smallest_string_length = strs[0].size();

        for (int i = 1; i < array_size; ++i) {
            int a = strs[i].size();
            if (a < smallest_string_length) {
                smallest_string_length = a;
            }
        }

        for (int i = 0; i < smallest_string_length; ++i) {
            char current_char = strs[0][i]; 
            for (int j = 1; j < array_size; ++j) {
                if (strs[j][i] != current_char) {
                    return prefix; 
                }
            }
            prefix += current_char; 
        }
        
        return prefix; 
    }
};
