class Solution {
public:
    int findTheWinner(int n, int k) {
        std::vector<int> arr;
        for (int i = 1; i <= n; ++i) { // create an arary from 1 to n
            arr.push_back(i);
        } 

        int idx = 0; // first position
        while (arr.size() > 1) {
            idx = (idx + k - 1) % arr.size(); // calculate the index of the friend to remove
            arr.erase(arr.begin() + idx);    // remove the friend from the vector
        }

        return arr.front(); // return the last remaining friend
    }
};
