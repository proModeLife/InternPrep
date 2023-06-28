class Solution:
    def numSquares(self, n: int) -> int:
        # dp = [float("inf") for _ in range(n)]
        # for i in range(n):
        #     maxInt = int(math.sqrt(i + 1))
        #     if (i + 1) == maxInt ** 2:
        #         dp[i] = 1
        #         continue
        #     for j in range(maxInt, 0, -1):
        #         dp[i] = min(dp[i], dp[i - j ** 2] + 1)
        # return dp[n - 1]

        def is_divided_by(x: int, count: int):
            if count == 1:
                return x == int(x**0.5) ** 2
            for i in squares:
                if i > x:
                    break
                if is_divided_by(x-i, count-1):
                    return True
            return False

        squares = [i * i for i in range(1, int(n**0.5)+1)]

        k = 1
        while not is_divided_by(n, k):
            k += 1
        assert k<5
        return k