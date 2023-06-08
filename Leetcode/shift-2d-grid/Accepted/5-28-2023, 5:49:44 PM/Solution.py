// https://leetcode.com/problems/shift-2d-grid

class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        k %= n * m
        si, sj = k // m, k % m
        
        # Flatten the grid into a 1D list
        flattened_grid = [num for row in grid for num in row]
        
        # Perform the shift
        shifted_grid = flattened_grid[-k:] + flattened_grid[:-k]
        
        # Reshape the shifted 1D list into a 2D grid
        shifted_grid = [shifted_grid[i:i+m] for i in range(0, n*m, m)]
        
        return shifted_grid
