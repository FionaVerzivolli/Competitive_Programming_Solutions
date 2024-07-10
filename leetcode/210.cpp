class Solution {
private:
    bool dfs(int numCourse, map<int, vector<int>>& adjacency, vector<int>& visited, vector<int>& cycle, vector<int>& order) {
        auto it = find(cycle.begin(), cycle.end(), numCourse);
        if (it != cycle.end()) {
            return false; 
        }
        
        auto it2 = find(visited.begin(), visited.end(), numCourse);
        if (it2 != visited.end()) {
            return true; 
        }
        
        cycle.push_back(numCourse);
        for (int c : adjacency[numCourse]) {
            if (!dfs(c, adjacency, visited, cycle, order)) {
                return false; 
            }
        }
        
        cycle.pop_back();
        visited.push_back(numCourse);
        order.push_back(numCourse);
        
        return true;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adjacency; 
        vector<int> visited;
        vector<int> cycle;
        vector<int> order;

        for (int i = 0; i < numCourses; ++i) {
            adjacency[i] = vector<int>();
        }

        for (const auto& prereq : prerequisites) {
            adjacency[prereq[0]].push_back(prereq[1]); 
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, adjacency, visited, cycle, order)) {
                return vector<int>(); 
            }
        }

        return order;
    }
};
