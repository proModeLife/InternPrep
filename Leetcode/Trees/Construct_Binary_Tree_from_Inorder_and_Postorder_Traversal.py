# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        location = {i: j for j, i in enumerate(inorder)}
        index = len(inorder) - 1

        def helper(left, right):
            nonlocal index
            if left > right:
                return None
            root_idx = location[postorder[index]]
            root_val = inorder[root_idx]
            index -= 1

            node = TreeNode(root_val)
            node.right = helper(root_idx + 1, right)
            node.left = helper(left, root_idx - 1)
            return node

        return helper(0, len(inorder) - 1)
