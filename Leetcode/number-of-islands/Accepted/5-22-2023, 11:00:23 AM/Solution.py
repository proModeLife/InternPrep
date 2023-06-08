// https://leetcode.com/problems/number-of-islands

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited=set()
        def covered(i,j):
            nonlocal visited
            if i>0 and grid[i-1][j]=='1' and (i-1,j) not in visited:
                visited.add((i-1,j))
                covered(i-1,j)
            if j>0 and grid[i][j-1]=='1' and (i,j-1) not in visited:
                visited.add((i,j-1))
                covered(i,j-1)
            if i< len(grid)-1 and grid[i+1][j]=='1' and (i+1,j) not in visited:
                visited.add((i+1,j))
                covered(i+1,j)
            if j< len(grid[0])-1 and grid[i][j+1]=='1' and (i,j+1) not in visited:
                visited.add((i,j+1))
                covered(i,j+1)
        ans=0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]=='1' and (i,j) not in visited:
                    visited.add((i,j))
                    covered(i,j)
                    ans+=1
        return ans


