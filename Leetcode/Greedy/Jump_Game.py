class Solution:
    def canJump(self, nums: List[int]) -> bool:
        i, curr = 1, nums[0]
        while i < len(nums) and curr >= i:
            curr = max(curr, i + nums[i])
            i += 1
        return i == len(nums)
