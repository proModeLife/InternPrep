// https://leetcode.com/problems/coin-change-ii

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp=[0]*(amount+1)
        dp[0]=1
        for i in range(len(coins)):
            for j in range(amount+1-coins[i]):
                if dp[j]>0:
                    dp[j+coins[i]]+=dp[j]
        return dp[amount]
