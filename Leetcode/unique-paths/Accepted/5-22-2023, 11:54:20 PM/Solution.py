// https://leetcode.com/problems/unique-paths

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        row = [1] * n

        for i in range(m - 1):
            newRow = [1] * n
            for j in range(1, n):
                newRow[j] = newRow[j - 1] + row[j]
            row = newRow
        return row[n-1]

        # O(n * m) O(n)
