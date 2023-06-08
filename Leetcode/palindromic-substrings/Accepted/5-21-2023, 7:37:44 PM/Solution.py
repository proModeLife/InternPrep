// https://leetcode.com/problems/palindromic-substrings

class Solution:
    def countSubstrings(self, s: str) -> int:
        dp = [[False] * len(s) for _ in range(len(s))]
        ans = 0
        
        def helper(i, j):
            nonlocal ans
            if i == j:
                ans += 1
            else:
                if s[i:j+1] == s[i:j+1][::-1]:
                    ans += 1
                if i < len(s) - 1 and not dp[i+1][j]:
                    dp[i+1][j] = True
                    helper(i+1, j)
                if j > 0 and not dp[i][j-1]:
                    dp[i][j-1] = True
                    helper(i, j-1)
        helper(0,len(s)-1)
        return ans