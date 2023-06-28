from typing import Optional, List
from collections import defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[TreeNode]:
        subtrees = defaultdict(list)
        
        def dfs(node):
            if not node:
                return 'null'
            h = f"{node.val},{dfs(node.left)},{dfs(node.right)}"
            subtrees[h].append(node)
            if len(subtrees[h]) == 2:
                ans.append(subtrees[h][0])
            return h
        
        ans = []
        dfs(root)
        return list(ans)
