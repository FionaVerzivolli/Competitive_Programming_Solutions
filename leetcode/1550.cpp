class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int tracker = 0;
        int range = arr.size() - 1;
        for(int i = 0; i < range; i++){
            if(tracker >= 2){
                return true;
            }
            if((arr[i] % 2 == 1) && (arr[i+1] %2 == 1)){
                tracker++;
            } else {
                if(tracker > 0){
                    tracker--;
                }
            }
        }
        if(tracker < 2){
            return false;
        }
        return true;    
    }
};
