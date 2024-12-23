class Solution {
public:
    bool isSubsequence(string s, string t) {
        int size = s.size();
        int index = 0;

        for(int i = 0; i < t.size(); i++){
            if(t[i] == s[index]){
                index++;
            }
        }

        return size == index;
    }
};
