class Solution:
    def maxProduct(self, s: str) -> int:

        def longestPalindromicSubseq(s):
            n = len(s)
            dp = [[0] * n for _ in range(n)]
            for i in range(n):
                dp[i][i] = 1
            for i in range(n - 1, -1, -1):
                for j in range(i + 1, n):
                    if s[i] == s[j]:
                        dp[i][j] = dp[i+1][j-1] + 2
                    else:
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1])
            return dp[0][n-1]
        

        LPS = longestPalindromicSubseq(s)

        s2 = ""
        i, j = 0, 0
        while i < len(s) and j < LPS:
            if s[i] == s[len(s)-j-1]:
                s2 += s[i]
                j += 1
            i += 1

        LPS2 = longestPalindromicSubseq(s2)
        
        return LPS * LPS2