class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        ans = 0
        for i in range(len(matrix)):
            if matrix[i][0] == "1":
                ans = 1
                break
        if ans == 0:
            for j in range(len(matrix[0])):
                if matrix[0][j] == "1":
                    ans = 1
                    break

        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][j] != "0":
                    matrix[i][j] = str(
                        min(
                            int(matrix[i - 1][j - 1]),
                            int(matrix[i - 1][j]),
                            int(matrix[i][j - 1]),
                        )
                        + 1
                    )
                    ans = max(ans, int(matrix[i][j]) ** 2)
        return ans
