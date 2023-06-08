// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [0] * (len(prices) + 2)
        ans = 0
        for i in range(len(prices) - 2, -1, -1):
            dp[i] = max(dp[i+1], -prices[i] + max(prices[j] + dp[j+2] for j in range(i+1, len(prices))))
            ans = max(dp[i], ans)
        return ans
