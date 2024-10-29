class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32> bit_a(a);
        bitset<32> bit_b(b);
        bitset<32> bit_c(c);

        int flip_count = 0;  

        for (int i = 0; i < 32; i++) {
            if (bit_c[i] == 0) {
                if (bit_a[i] == 1) flip_count++;  
                if (bit_b[i] == 1) flip_count++; 
            } 
            else {
                if (bit_a[i] == 0 && bit_b[i] == 0) {
                    flip_count++;  
                }
            }
        }
        return flip_count;
    }
};
