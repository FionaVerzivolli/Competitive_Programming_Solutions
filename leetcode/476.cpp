class Solution {
public:
    int findComplement(int num) {
        int a = num;
        int iter = 0;
        int complement = 0;
        while(a > 0){
            if(a % 2 == 0){
                complement += pow(2, iter);
            }
            a = a / 2;
            iter++;
        }
        return complement;
    }
};
