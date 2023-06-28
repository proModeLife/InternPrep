class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # observational method
        total = sum(nums)

        if abs(target) > total or (target - total) % 2:
            return 0

        diff = (
            total - target
        )  # the difference which we need to cover up using various ways
        diff //= 2
        dp = [0] * (diff + 1)
        dp[0] = 1
        for i in range(len(nums)):
            for j in range(diff, nums[i] - 1, -1):
                dp[j] += dp[j - nums[i]]
        return dp[diff]

        # backtracking + dp
        dp = {}

        def backtrack(i, total):
            if i == len(nums):
                return total == target
            elif (i, total) in dp:
                return dp[(i, total)]
            else:
                dp[(i, total)] = backtrack(i + 1, total + nums[i]) + backtrack(
                    i + 1, total - nums[i]
                )
                return dp[(i, total)]

        return backtrack(0, 0)
