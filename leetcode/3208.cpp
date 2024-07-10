class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int num = 0;
        int right = 0;
        int left = 0;
        int s = colors.size();
        
        if (s == 0 || k == 0) {
            return num;
        }
        
        for (int j = 0; j < k; j++) {
            colors.push_back(colors[j]);
        }
        
        for (int i = 0; i < s + k - 1; i++) {
            if (colors[i] != colors[i + 1]) {
                right++;
            } else {
                right = left + 1; 
            }
            
            if (right - left >= k) {
                num++;
            }
        }
        
        return num;
    }
};
