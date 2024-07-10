class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double s = customers.size();
        double time = customers[0][0];
        double total_wait = 0;
        for(int i = 0; i < s; i++){
            if(customers[i][0] >= time ){
                time = customers[i][0] + customers[i][1]; // go to next time
                total_wait += customers[i][1]; // add time to wait time
            }else{
                // add difference in time 
                total_wait += (time + customers[i][1]) - customers[i][0];
                time += customers[i][1]; // move the time
            }
            }
        return total_wait/s;

    }
};
