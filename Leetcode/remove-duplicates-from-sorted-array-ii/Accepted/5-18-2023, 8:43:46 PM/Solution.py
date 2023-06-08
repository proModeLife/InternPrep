// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        L=1
        curr=nums[0]
        bulb=True
        for R in range(1,len(nums)):
            if bulb:
                if nums[R]==curr:
                    nums[L]=curr
                    L+=1
                    bulb=False
                if nums[R]>curr:
                    curr=nums[R]
                    nums[L]=curr
                    L+=1
            else:
                if nums[R]>curr:
                    curr=nums[R]
                    nums[L]=nums[R]
                    L+=1
                    bulb=True
        return L