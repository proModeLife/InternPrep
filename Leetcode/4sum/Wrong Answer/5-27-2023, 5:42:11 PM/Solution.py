// https://leetcode.com/problems/4sum

from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        result = []
        

        def threeSum(start, target, nums, result):
            for index in range(start + 1, len(nums)):
                if nums[index] > target:
                    break
                if index > start + 1 and nums[index] == nums[index - 1]:
                    continue
                left, right = index + 1, len(nums) - 1
                while left < right:
                    if nums[left] + nums[right] + nums[index] < target:
                        left += 1
                    elif nums[left] + nums[right] + nums[index] > target:
                        right -= 1
                    else:
                        result.append([nums[start], nums[index], nums[left], nums[right]])
                        left += 1
                        right -= 1
                        while left < right and nums[left] == nums[left - 1]:
                            left += 1
        threeSum(0, target - nums[0], nums, result)
        count=0
        for i in range(1,len(nums)):
            if nums[i]==nums[i-1]:
                continue
            threeSum(i,target-nums[i],nums,result)   
        return result
