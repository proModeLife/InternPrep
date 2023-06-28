class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        def dfs(i, j):
            nonlocal curr
            if i < 0 or j < 0 or i == len(grid) or j == len(grid[0]):
                return 0
            if grid[i][j] != 1:
                return 1
            grid[i][j] = 2
            curr += 1
            return dfs(i + 1, j) * dfs(i, j + 1) * dfs(i - 1, j) * dfs(i, j - 1)

        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    curr = 0
                    val = dfs(i, j)
                    ans += curr * val
        return ans
