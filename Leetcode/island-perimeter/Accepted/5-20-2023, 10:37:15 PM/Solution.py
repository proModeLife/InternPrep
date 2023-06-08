// https://leetcode.com/problems/island-perimeter

class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        visit=set()
        def dfs(i,j):
            if i>=len(grid) or j>=len(grid[0]) or i<0 or j<0 or grid[i][j]==0 :
                return 1
            elif (i,j) in visit:
                return 0
            else:
                visit.add((i,j))
                ans=dfs(i,j+1)
                ans+=dfs(i+1,j)
                ans+=dfs(i-1,j)
                ans+=dfs(i,j-1)
                return ans
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    return dfs(i,j)
        return 0
