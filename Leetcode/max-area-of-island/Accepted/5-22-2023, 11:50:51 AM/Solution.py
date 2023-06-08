// https://leetcode.com/problems/max-area-of-island

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        def dfs(i,j):
            ret = 1
            if i>0 and grid[i-1][j]==1:
                grid[i-1][j]=0
                ret+=dfs(i-1,j)
            if j>0 and grid[i][j-1]==1:
                grid[i][j-1]=0
                ret+=dfs(i,j-1)
            if i+1<len(grid) and grid[i+1][j]==1:
                grid[i+1][j]=0
                ret+=dfs(i+1,j)
            if j+1<len(grid[0]) and grid[i][j+1]==1:
                grid[i][j+1]=0
                ret+=dfs(i,j+1)
            return ret
        
        ans=0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    grid[i][j]=0
                    ans=max(ans,dfs(i,j))
        return ans