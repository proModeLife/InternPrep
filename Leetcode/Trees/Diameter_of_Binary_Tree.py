class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        max_diameter = 0
        def maxDepth(node: TreeNode) -> int:
            nonlocal max_diameter
            if not node:
                return 0
            left_depth = maxDepth(node.left)
            right_depth = maxDepth(node.right)
            max_diameter = max(max_diameter, left_depth + right_depth)
            return 1 + max(left_depth, right_depth)
        
        maxDepth(root)
        return max_diameter