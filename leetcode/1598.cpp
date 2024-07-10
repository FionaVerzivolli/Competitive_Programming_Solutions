class Solution {
public:
    int minOperations(vector<string>& logs) {
        int stack = 0;
        for(int i = 0; i < logs.size(); i++){
            if(logs[i] == "../" && stack > 0){
                stack--; // move one directory up
            } else if(logs[i] != "./" && logs[i] != "../") {
                stack++; // move one directory down
            }
        }
        return stack;
    }
};
