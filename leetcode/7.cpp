class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;

        int abs_x = std::abs(x);

        std::string num_string = std::to_string(abs_x);

        int length = num_string.size();
        for (int i = 0; i < length / 2; i++) {
            char temp = num_string[i];
            num_string[i] = num_string[length - 1 - i];
            num_string[length - 1 - i] = temp;
        }

        long reversed_num = std::stol(num_string); 

        if (reversed_num > INT_MAX || reversed_num < INT_MIN) {
            return 0;
        }

        if (x < 0) {
            reversed_num = -reversed_num;
        }

        return static_cast<int>(reversed_num);
    }
};

