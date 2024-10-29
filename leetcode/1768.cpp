class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged = "";

        int a = word1.size();
        int b = word2.size();

        int start = 0;

        while(start < a && start < b){
            merged += word1[start];
            merged += word2[start];
            start++;
        }
        if(start == a){
            for(int i = start; i < b; i++){
                merged += word2[i];
            }
        }else if(start == b){
            for(int i = start; i < a; i++){
                merged += word1[i];
            }
        }
        return merged;
                
    }
};
