// https://leetcode.com/problems/number-of-islands

from collections import deque

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited = set()
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        m, n = len(grid), len(grid[0])
        ans = 0
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1' and (i, j) not in visited:
                    ans += 1
                    queue = deque([(i, j)])
                    visited.add((i, j))
                    while queue:
                        x, y = queue.popleft()
                        for dx, dy in directions:
                            nx, ny = x + dx, y + dy
                            if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == '1' and (nx, ny) not in visited:
                                queue.append((nx, ny))
                                visited.add((nx, ny))
        
        return ans