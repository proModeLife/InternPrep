class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        dp = [[-1] * (n2 + 1) for i in range(n1 + 1)]
        dp[n1][n2] = 0
        for i in range(n1):
            dp[i][n2] = 0
        for i in range(n2):
            dp[n1][i] = 0
        for i in range(n1 - 1, -1, -1):
            for j in range(n2 - 1, -1, -1):
                if nums1[i] == nums2[j]:
                    dp[i][j] = 1 + dp[i + 1][j + 1]
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])
        return dp[0][0]
