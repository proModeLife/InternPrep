# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        ans=[]
        q=deque()
        q.append(root)
        flip=False
        while q:
            level=[]
            cap=len(q)
            for _ in range(cap):
                node=q.popleft()
                level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if flip: ans.append(reversed(level))
            else: ans.append(level)
            flip= not flip
        return ans