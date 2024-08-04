class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        // check if sorted arrays are equal? think of insertion sort,
        // similar to that? you can keep swapping/"reversing" the order of 
        // any two adjacent ints until the list is sorted. Can also keep
        // swapping any two adjacent ints until the target == arr if they have
        // the same integers and frequency of elements. This is because
        // you can generate any arrangement from simply swapping adjacent
        // ints. Thus, compare them sorted to check for frequency and integers.

        std::sort(target.begin(), target.end());
        std::sort(arr.begin(), arr.end());

        if(target == arr){
            return true;
        }
        return false;
    }
};
