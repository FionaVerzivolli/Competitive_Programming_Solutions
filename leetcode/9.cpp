class Solution {
public:
    bool isPalindrome(int x) {
        int start = 0;
        std::string NewVar = std::to_string(x);
        int end = NewVar.size() - 1;
        while(start < end){
            if(NewVar[start] != NewVar[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
