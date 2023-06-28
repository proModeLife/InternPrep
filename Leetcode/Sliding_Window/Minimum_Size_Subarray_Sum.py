class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        if sum(nums) < target:
            return 0
        l, r = 0, 0
        curr = 0
        ans = float('inf')
        while r < len(nums):
            while curr < target and r < len(nums):
                curr += nums[r]
                r += 1
            while curr >= target and l <= r:
                ans = min(ans, r - l)
                curr -= nums[l]
                l += 1
        return ans if ans != float('inf') else 0