class Solution {
public:
    std::string largestGoodInteger(std::string num) {
        std::string max = ""; 
        for (int i = 0; i <= num.size() - 3; i++) { 
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                std::string new_int = num.substr(i, 3); 
                if (new_int > max) {
                    max = new_int;
                }
            }
        }
        return max;
    }
};
