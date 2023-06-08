// https://leetcode.com/problems/number-of-islands

import numpy as np

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        grid = np.array(grid)
        visited = set()
        def covered(i,j):
            nonlocal visited
            if i >= 0 and j >= 0 and i < grid.shape[0] and j < grid.shape[1] and grid[i][j] == '1' and (i,j) not in visited:
                visited.add((i,j))
                covered(i-1,j)
                covered(i+1,j)
                covered(i,j-1)
                covered(i,j+1)
        
        ans = 0
        for i in range(grid.shape[0]):
            for j in range(grid.shape[1]):
                if grid[i][j] == '1' and (i,j) not in visited:
                    ans += 1
                    covered(i,j)
        
        return ans