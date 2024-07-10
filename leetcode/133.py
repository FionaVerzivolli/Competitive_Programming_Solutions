"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        
        clone_map = {}
        
        def dfs(original_node):
            if original_node in clone_map:
                return clone_map[original_node]
            
            clone_node = Node(original_node.val)
            
            clone_map[original_node] = clone_node
            
            for neighbor in original_node.neighbors:
                clone_node.neighbors.append(dfs(neighbor))
            
            return clone_node
        
        return dfs(node)
