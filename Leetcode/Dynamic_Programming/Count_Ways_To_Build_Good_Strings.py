class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        dp = [0] * (high + 1)
        min_, max_ = min(one, zero), max(one, zero)
        ptr = min_
        while ptr < max_ + 1:
            dp[ptr] = 1
            ptr += min_
        dp[max_] += 1
        mod = pow(10, 9) + 7
        for i in range(max_ + 1, high + 1):
            dp[i] = (dp[i - min_] + dp[i - max_]) % mod
        return sum(dp[low : high + 1]) % mod
