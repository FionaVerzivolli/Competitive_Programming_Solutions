class Solution {
public:
    int passThePillow(int n, int time) {
        int rounds = time / (n - 1); // number of rounds
        int position = time % (n - 1); // position of ball
        if(rounds % 2 == 1){
            return n - position;
        }
        return position + 1;
    }
};
