class Solution {
public:
    string getEncryptedString(string s, int k) {
        int length = s.size();
        string n = s; 
        
        for (int i = 0; i < length; ++i) {
 
            int newPos = (i + k) % length;
            n[newPos] = s[i]; 
        }
        
        return n;
    }
};
