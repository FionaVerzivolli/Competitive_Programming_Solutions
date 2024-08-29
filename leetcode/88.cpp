class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // compare indices
        int c1 = 0;
        int c2 = 0;
        
        std::vector<int> vec; 
        while(c1 < m && c2 < n){
            if(nums1[c1] < nums2[c2]){
                vec.push_back(nums1[c1]);
                c1++;
            }else{
                vec.push_back(nums2[c2]);
                c2++;
                }
            }
        
        if(c1 == m){
            for(int i = c2; i < n; i++){
                vec.push_back(nums2[i]);
            }
        }
        
        if(c2 == n){
            for(int i = c1; i < m; i++){
                vec.push_back(nums1[i]);
            }
        }
        nums1 = vec;

        }
    };
