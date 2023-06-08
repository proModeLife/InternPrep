// https://leetcode.com/problems/brick-wall

class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        edges={}
        for i in range(len(wall)):
            edge=0
            for j in range(len(wall[i])-1):
                edge+=wall[i][j]
                if not edge in edges:
                    edges[edge]=0
                edges[edge]+=1
        less=0
        for i in edges:
            less=max(less,edges[i])
        return len(wall)-less
                


