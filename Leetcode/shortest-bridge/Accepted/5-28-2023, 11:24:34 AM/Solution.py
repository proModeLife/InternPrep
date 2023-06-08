// https://leetcode.com/problems/shortest-bridge

from typing import List
from collections import deque

class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        paths = deque()
        visited = set()  # Track visited cells to avoid revisiting

        def dfs(i, j):
            if i < 0 or j < 0 or i == n or j == m or grid[i][j] == 2:
                return
            elif grid[i][j] == 0:
                grid[i][j] = 2
                paths.append((i, j))
                return
            grid[i][j] = 2
            dfs(i + 1, j)
            dfs(i, j + 1)
            dfs(i - 1, j)
            dfs(i, j - 1)

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    dfs(i, j)
                    break
            if paths:  # If the first island is found, break out of the loop
                break

        flips = 1
        while paths:
            for _ in range(len(paths)):  # Process all cells in the current level
                i, j = paths.popleft()
                if (i, j) in visited:
                    continue
                visited.add((i, j))
                if i > 0 and grid[i - 1][j] == 1 or \
                   j > 0 and grid[i][j - 1] == 1 or \
                   i < n - 1 and grid[i + 1][j] == 1 or \
                   j < m - 1 and grid[i][j + 1] == 1:
                    return flips
                if i > 0 and grid[i - 1][j] == 0:
                    paths.append((i - 1, j))
                if j > 0 and grid[i][j - 1] == 0:
                    paths.append((i, j - 1))
                if i < n - 1 and grid[i + 1][j] == 0:
                    paths.append((i + 1, j))
                if j < m - 1 and grid[i][j + 1] == 0:
                    paths.append((i, j + 1))
            flips += 1

        return -1  # If the second island is not found

