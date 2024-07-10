int stink(int smallest, int largest) {
    int count = 0;
    int height1 = 0;
    
    for (int i = 0; i < 100; i++) {
        if (count == 1) {
            if ((smallest - i) < 0) {
                break;
            } else {
                smallest -= i;
                count = 0;
                height1 += 1;
            }
        } else {
            if ((largest - i) < 0) {
                break;
            } else {
                largest -= i;
                count = 1;
                height1 += 1;
            }
        }
    }
    
    return height1;
}

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int height1 = stink(red, blue);
        int height2 = stink(blue, red);

        if (height2 > height1) {
            height1 = height2;
        }
        
        return height1 - 1;
    }
};
