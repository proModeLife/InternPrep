// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution:
    def findMin(self, nums: List[int]) -> int:
        l,r=0,len(nums)-1
        m=0
        while l<=r:
            m=(l+r)//2
            if nums[m]>nums[l] and nums[l] > nums[r]:
                l=m+1
            elif nums[m] < nums[r] : 
                r=m-1
            else:
                return nums[m]
        return nums[m]
        
