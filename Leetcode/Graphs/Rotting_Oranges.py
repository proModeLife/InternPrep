from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # Define the four possible directions to move in the grid
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        # Initialize the queue and the time counter
        queue = deque()
        time = 0
        
        # Add all the initially rotten oranges to the queue and mark them as visited
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    queue.append((i, j))
        
        # Perform a BFS to simulate the rotting process
        while queue:
            # Process all the oranges at the current level
            for _ in range(len(queue)):
                x, y = queue.popleft()
                for dx, dy in directions:
                    nx, ny =x + dx, y + dy
                    if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and grid[nx][ny] == 1:
                        grid[nx][ny] = 2
                        queue.append((nx, ny))
            
            # Increment the time counter after each level
            if queue:
                time += 1
        
        # Check if there are any fresh oranges left in the grid
        for row in grid:
            if 1 in row:
                return -1
        
        # Return the total time it took for all the oranges to rot
        return time