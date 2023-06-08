// https://leetcode.com/problems/diameter-of-binary-tree

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        def maxDepth(node: TreeNode) -> int:
            if not node:
                return 0
            left_depth = maxDepth(node.left)
            right_depth = maxDepth(node.right)
            self.max_diameter = max(self.max_diameter, left_depth + right_depth)
            return 1 + max(left_depth, right_depth)
        
        self.max_diameter = 0
        maxDepth(root)
        return self.max_diameter