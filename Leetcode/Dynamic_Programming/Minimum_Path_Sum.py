class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        prev = grid[-1]
        for i in range(len(prev) - 2, -1, -1):
            prev[i] += prev[i + 1]
        for r in range(len(grid) - 2, -1, -1):
            curr = grid[r]
            curr[-1] += prev[-1]
            for i in range(len(prev) - 2, -1, -1):
                curr[i] += min(prev[i], curr[i + 1])
            prev = curr
        return prev[0]
