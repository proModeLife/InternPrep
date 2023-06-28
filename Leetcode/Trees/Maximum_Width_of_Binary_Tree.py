from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0

        queue = deque([(root, 0)])
        max_width = 1

        while queue:
            level_length = len(queue)
            _, level_start = queue[0]

            for _ in range(level_length):
                node, position = queue.popleft()
                if node.left:
                    queue.append((node.left, 2 * position))
                if node.right:
                    queue.append((node.right, 2 * position + 1))

            if queue:
                if len(queue) == 1:
                    node, position = queue.popleft()
                    queue = deque([(node, 0)])
                max_width = max(max_width, queue[-1][1] - queue[0][1] + 1)

        return max_width
