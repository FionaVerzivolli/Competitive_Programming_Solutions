# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def getmins(self, root: Optional[TreeNode]):
            mins = []
            if not root:
                return []
            if not root.left and not root.right:
                return [root.val]
            else:
                mins.extend(getmins(self, root.left))
                mins.extend(getmins(self, root.right))
            return mins

        leaves1 = getmins(self, root1)
        print(leaves1)
        leaves2 = getmins(self, root2)
        print(leaves2)
        return leaves1 == leaves2
        
