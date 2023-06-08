// https://leetcode.com/problems/house-robber-ii

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        rob1, rob2 = 0, 0
        nums+=nums
        for n in nums:
            temp = max(n + rob1, rob2)
            rob1 = rob2
            rob2 = temp
        return rob2//2