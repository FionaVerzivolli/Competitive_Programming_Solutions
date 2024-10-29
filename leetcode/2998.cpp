class Solution {
public:
    bool vis[11001];
    int minimumOperationsToMakeEqual(int x, int y) {
        queue <pair<int, int>> q;
        q.push({x, 0});
        
        while (q.size()) {
            int cur = q.front().first;
            int t = q.front().second;
            q.pop();
            
            if (cur == y){
                return t;
            }
            vis[cur] = 1;
            if (cur % 5 == 0 and vis[cur / 5] == 0){
                q.push({cur / 5, t + 1});
            }if (cur % 11 == 0 and vis[cur / 11] == 0){
                q.push({cur / 11, t + 1});
            }
            if (cur + 1 <= 11000 and vis[cur + 1] == 0)
                q.push({cur + 1, t + 1});
            if (cur - 1 >= 0 and vis[cur - 1] == 0)
                q.push({cur - 1, t + 1});
        }
        
        return 0;
    }
};
