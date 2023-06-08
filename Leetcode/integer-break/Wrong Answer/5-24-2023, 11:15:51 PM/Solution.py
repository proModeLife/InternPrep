// https://leetcode.com/problems/integer-break

class Solution:
    def integerBreak(self, n: int) -> int:
        dp=[1]*(n+1)
        if n>=4:
            dp[4]=4
        for i in range(5,n+1):
            for j in range(i):
                dp[i]=max(dp[i],j*dp[i-j])


        return dp[n]