class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        graph = defaultdict(list)
        for from_node, to_node in edges:
            graph[to_node].append(from_node)
        
        def dfs(node, visited, ancestors):
            for ancestor in graph[node]:
                if ancestor not in visited:
                    visited.add(ancestor)
                    ancestors.add(ancestor)
                    dfs(ancestor, visited, ancestors)
        
        answer = []
        for i in range(n):
            ancestors = set()
            visited = set()
            dfs(i, visited, ancestors)
            answer.append(sorted(ancestors))
        
        return answer
