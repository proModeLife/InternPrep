// https://leetcode.com/problems/largest-number

from typing import List

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        for i in range(len(nums)):
            for j in range(len(nums)-1):
                val1 = "".join(map(str, nums))
                nums[j],nums[j+1]=nums[j+1],nums[j]
                val2 = "".join(map(str, nums))
                if int(val2)<int(val1):
                    nums[j],nums[j+1]=nums[j+1],nums[j]
        return "".join(map(str, nums))