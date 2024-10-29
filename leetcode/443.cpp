class Solution {
public:
    int compress(std::vector<char>& chars) {
        int group_size = 0;
        bool last_char = false;
        int writeIndex = 0;
        int size = 0;

        for (int i = 0; i < chars.size(); i++) {
            group_size++;

            if (i + 1 >= chars.size() || chars[i] != chars[i + 1]) {
                chars[writeIndex++] = chars[i]; 
                size++;

                if (group_size > 1) {
                    for (char c : to_string(group_size)) {
                        chars[writeIndex++] = c;
                    }
                    size += to_string(group_size).length(); 
                }

                group_size = 0;
            }
        }

        chars.resize(writeIndex);
        return size; 
    }
};
