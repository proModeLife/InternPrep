// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        n = len(days)
        durations = [1, 7, 30]
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            for j in range(3):
                k = i - 1
                while k >= 0 and days[k] > days[i-1] - durations[j]:
                    k -= 1
                dp[i] = min(dp[i], dp[k+1] + costs[j])
        return dp[n]