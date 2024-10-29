class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int val = 0;
            for (int j = 0; j<31; ++j){
                val += ((i&(1<<j)) != 0);
            }
            ans.push_back(val);
        }
        return ans;
    }
};
