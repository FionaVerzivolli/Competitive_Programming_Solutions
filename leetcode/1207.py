class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurs;

        for(int i = 0; i < arr.size(); i++){
            occurs[arr[i]]++;
        }
        vector<int> vals;
    
        for(const auto& pair : occurs){  
            vals.push_back(pair.second);
        }
        
        set<int> set1(vals.begin(), vals.end());

        return set1.size() == vals.size();
    }
};
