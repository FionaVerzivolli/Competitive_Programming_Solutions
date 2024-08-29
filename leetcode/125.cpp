class Solution {
public:
    bool isPalindrome(string s) {
        std::string s1;
        for (char ch : s) {
            char lower_ch = std::tolower(static_cast<unsigned char>(ch));
        
            if (std::isalnum(static_cast<unsigned char>(lower_ch))) {
                s1 += lower_ch;
            }
        }
        
        for(int i = 0; i < s1.size() / 2; i++){
            if(s1[i] != s1[s1.size() - 1 - i]){
                return false;
            }
        }
        return true;
    }

};
