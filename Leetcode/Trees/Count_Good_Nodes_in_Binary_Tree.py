# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        ans = 0

        def dfs(node, val):
            nonlocal ans
            if node.val >= val:
                val = node.val
                ans += 1
            if node.left:
                dfs(node.left, val)
            if node.right:
                dfs(node.right, val)

        dfs(root, -1e5)
        return ans
