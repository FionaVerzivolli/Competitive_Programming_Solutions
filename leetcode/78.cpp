class Solution {
public:
    vector <int> nw(vector<int> &v1){
        vector <int> ret;
        for (int x : v1){
            ret.push_back(x);
        }
        return ret;
    }
    vector<vector<int>> calc(vector<vector<int>> &ans, vector<int> &num, int i){
        if (i == num.size()){
            return ans;
        }
        int cur = ans.size();
        for (int j = 0; j<cur; ++j){
            auto lst = nw(ans[j]);
            lst.push_back(num[i]);
            ans.push_back(lst);
        }

        return calc(ans, num, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> tmp;
        v.push_back(tmp);
        return calc(v, nums, 0);
    }
};
