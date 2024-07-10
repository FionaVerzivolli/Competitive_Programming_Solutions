class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = 0;
        int full = numBottles;
        int empty = 0;
        if (numBottles < numExchange){
            return numBottles;
        }
        
        while (numBottles >= numExchange){
            totalDrank += full;
            full = numBottles / numExchange;
            empty = numBottles % numExchange;
            numBottles = full + empty;
        }
        return totalDrank + full;
    }
};
