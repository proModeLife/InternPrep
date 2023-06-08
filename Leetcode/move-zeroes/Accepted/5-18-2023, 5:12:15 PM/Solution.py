// https://leetcode.com/problems/move-zeroes

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i,j=0,0
        while i<len(nums) and j<len(nums):
            if nums[i]==0:
                j=i
                while j<len(nums) and nums[j]==0 :
                    j+=1
                if j<len(nums):
                    nums[i],nums[j]=nums[j],nums[i]
                    i+=1
            else:
                i+=1
                j+=1
