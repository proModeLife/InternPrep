// https://leetcode.com/problems/majority-element

from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if not nums:
            return None
        if len(nums) == 1:
            return nums[0]
        a = self.majorityElement(nums[0:len(nums)//2])
        b = self.majorityElement(nums[len(nums)//2:])
        if a == b:
            return a
        count_a = sum(1 for i in nums if i == a)
        count_b = sum(1 for i in nums if i == b)
        return a if count_a > count_b else b