// https://leetcode.com/problems/binary-tree-postorder-traversal

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return None
        res, stack = [], []
        cur = root
        
        while cur or stack:
            if cur:
                stack.append(cur)
                res.insert(0, cur.val)
                cur = cur.right
            else:
                node = stack.pop()
                cur = node.left
        
        return res