class Solution {
public:
    int bestClosingTime(string customers) {
        int size = customers.size();
        
        int penalty_so_far = 0;
        for (char c : customers) {
            if (c == 'Y') penalty_so_far++;
        }
        
        int min_penalty = penalty_so_far;
        int best_hour = 0;
        
        for (int hour = 1; hour <= size; hour++) {
            if (customers[hour - 1] == 'Y') {
                penalty_so_far--;  
            } else {
                penalty_so_far++; 
            }
            
            if (penalty_so_far < min_penalty) {
                min_penalty = penalty_so_far;
                best_hour = hour;
            }
        }
        
        return best_hour;
    }
};
