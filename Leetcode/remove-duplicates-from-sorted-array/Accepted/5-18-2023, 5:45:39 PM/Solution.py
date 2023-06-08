// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums)<=1:
            return len(nums)
        slow =0
        count=1
        fast=0
        while fast<len(nums):
            curr=nums[fast]
            if nums[fast] > nums[slow]:
                slow+=1
                nums[slow]=nums[fast]
                count+=1
                while fast <len(nums) and nums[fast]==curr:
                    fast+=1
                fast-=1
            fast+=1
            
        return count

    

