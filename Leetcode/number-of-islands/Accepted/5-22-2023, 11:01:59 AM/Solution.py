// https://leetcode.com/problems/number-of-islands

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited = set()
        def covered(i,j):
            nonlocal visited
            if i >= 0 and j >= 0 and i < len(grid) and j < len(grid[0]) and grid[i][j] == '1' and (i,j) not in visited:
                visited.add((i,j))
                covered(i-1,j)
                covered(i+1,j)
                covered(i,j-1)
                covered(i,j+1)
        
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1' and (i,j) not in visited:
                    ans += 1
                    covered(i,j)
        
        return ans