// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mn=prices[0]
        mx=prices[0]
        profit=0
        for price in prices:
            if price>mx:
                mx=price
                profit=max(profit,mx-mn)
            if price<mn:
                mn=price
                mx=price
        return profit
            