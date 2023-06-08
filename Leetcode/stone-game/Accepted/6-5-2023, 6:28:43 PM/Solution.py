// https://leetcode.com/problems/stone-game

class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = [0] * n
        for i in range(n-1, -1, -1):
            for j in range(i, n):
                if i == j:
                    dp[j] = piles[i]
                else:
                    take_left = piles[i] + min(dp[j], dp[j-1])
                    take_right = piles[j] + min(dp[j-1], dp[j-2] if j > 1 else 0)
                    dp[j] = max(take_left, take_right)
        return dp[n-1] > sum(piles) / 2