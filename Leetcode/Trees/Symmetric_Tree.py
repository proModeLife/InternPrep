# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def isSame(node1,node2):
            if (node1 and not node2) or (node2 and not node1) or (node1 and node2 and node1.val!=node2.val):
                return False
            elif not node1 and not node2:
                return True
            else: return isSame(node1.left,node2.right) and isSame(node1.right,node2.left)
        return isSame(root.left,root.right) if root else True
            