// https://leetcode.com/problems/sort-colors

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        change=True
        while change:
            change=False
            for i in range(len(nums)):
                for j in range(i,len(nums)):
                    if nums[i]==1 and nums[j]==0:
                        nums[j]=1
                        nums[i]=0
                        change=True
                    if nums[i]==2 and nums[j]==1:
                        nums[i]=1
                        nums[j]=2
                        change=True