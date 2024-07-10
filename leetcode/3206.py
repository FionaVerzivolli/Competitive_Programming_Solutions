class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        // array ends
        int s = colors.size();
        int num = 0;
        if (s == 0){
            return num;
        }
        if(colors[0] != colors[s - 1]){
            if(colors[1] == colors[s - 1]){
                num++;
            }if (colors[s - 2] == colors[0]){
                num++;
            }
        }
        for (int i = 0; i < s - 2; i++) {
            if (colors[i] != colors[i + 1] && colors[i] == colors[i + 2]) {
                num++;
            }
        }
        return num;
    }
};
