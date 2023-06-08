// https://leetcode.com/problems/brick-wall

class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        widht=sum(wall[0])
        edges=[0]*(widht+1)
        for i in range(len(wall)):
            edge=0
            for j in range(len(wall[i])-1):
                edge+=wall[i][j]
                edges[edge]+=1
        less=0
        for i in range(len(edges)-1):
            less=max(less,edges[i])
        return len(wall)-less
                


