// https://leetcode.com/problems/shortest-path-in-binary-matrix

from typing import List

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        # Check if the starting or ending cell is blocked
        if grid[0][0] == 1 or grid[-1][-1] == 1:
            return -1
        
        # Define the 8 possible directions of movement
        directions = [(1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (-1, -1), (1, -1), (-1, 1)]
        
        # Initialize the queue with the starting position and its cost
        queue = [(0, 0, 1)]
        
        # Mark the starting cell as visited
        grid[0][0] = 1
        
        # Perform BFS
        while queue:
            # Pop the first cell from the queue
            i, j, cost = queue.pop(0)
            
            # Check if we have reached the ending cell
            if i == len(grid) - 1 and j == len(grid[0]) - 1:
                return cost
            
            # Explore the neighbors of the current cell
            for di, dj in directions:
                ni, nj = i + di, j + dj
                
                # Check if the neighbor is within bounds and unvisited
                if 0 <= ni < len(grid) and 0 <= nj < len(grid[0]) and grid[ni][nj] == 0:
                    # Mark the neighbor as visited and add it to the queue
                    grid[ni][nj] = 1
                    queue.append((ni, nj, cost + 1))
        
        # If we have not found the ending cell, return -1
        return -1