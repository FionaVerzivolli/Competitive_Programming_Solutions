#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxer(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& memo) {

        if (memo[y][x] != -1) return memo[y][x];
        
        int curr = grid[y][x];
        int pot1 = 0, pot2 = 0, pot3 = 0;

        if (y - 1 >= 0 && x + 1 < grid[0].size() && grid[y - 1][x + 1] > curr) {
            pot1 = 1 + maxer(x + 1, y - 1, grid, memo);
        }

        if (x + 1 < grid[0].size() && grid[y][x + 1] > curr) {
            pot2 = 1 + maxer(x + 1, y, grid, memo);
        }

        if (y + 1 < grid.size() && x + 1 < grid[0].size() && grid[y + 1][x + 1] > curr) {
            pot3 = 1 + maxer(x + 1, y + 1, grid, memo);
        }

        memo[y][x] = max({pot1, pot2, pot3});
        return memo[y][x];
    }

    int maxMoves(vector<vector<int>>& grid) {
        int moves = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1)); 

        for (int i = 0; i < m; i++) {
            moves = max(moves, maxer(0, i, grid, memo));
        }
        return moves;
    }
};
