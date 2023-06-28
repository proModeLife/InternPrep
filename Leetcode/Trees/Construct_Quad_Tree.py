"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':

        def helper(n,r,c):
            allSame=True
            for i in range(n):
                for j in range(n):
                    if grid[r][c]!=grid[r+i][c+j]:
                        allSame=False
                        break
            if allSame:
                return Node(grid[r][c],True)
            n//=2
            tl=helper(n,r,c)
            tr=helper(n,r,c+n)
            bl=helper(n,r+n,c)
            br=helper(n,r+n,c+n)
            return Node(0,False,tl,tr,bl,br)
        return helper(len(grid),0,0)
