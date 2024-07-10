class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        
        while (i < n && s[i] == ' ') {
            i++; //get rid of leading whitespace. dont care ab 0, because 0 * 10 = 0
        }
        
        int sign = 1;  //positive
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }
        
        long long result = 0; //avoid overflow, use long long
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0'; //ascii conversion
            
            if (result > (INT_MAX - digit) / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == -1) ? INT_MIN : INT_MAX;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return result * sign;
    }
};
