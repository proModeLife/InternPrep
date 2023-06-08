// https://leetcode.com/problems/majority-element

from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = None
        count = 0
        for num in nums:
            if count == 0:
                candidate = num
            count += 1 if num == candidate else -1
        count = sum(1 for num in nums if num == candidate)
        return candidate if count > len(nums)//2 else None