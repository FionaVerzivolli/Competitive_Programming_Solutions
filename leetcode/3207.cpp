class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long s = enemyEnergies.size();
        long long a = currentEnergy;
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if(a < enemyEnergies[0]){
            return 0;
        }
        for(long long i = 1; i < s; i++){
            a += enemyEnergies[i];
        }
 
        return a / enemyEnergies[0];


    }
};
