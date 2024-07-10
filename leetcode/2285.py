class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        # 1. find vertex with highest degree, then second, third, etc. 
        # 2. replace the vertexes with the labels
        # 3. add all of the road sums together and return it
        degrees = defaultdict(int)
        for road in roads:
            degrees[road[0]] += 1
            degrees[road[1]] += 1
        
        sorted_vertices = sorted(degrees, key=degrees.get, reverse=True)
        
        importance = {}
        for i, vertex in enumerate(sorted_vertices):
            importance[vertex] = n - i
        
        total_importance = 0
        for road in roads:
            total_importance += importance[road[0]] + importance[road[1]]
        
        return total_importance
