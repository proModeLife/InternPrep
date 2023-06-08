// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution:
    def findMin(self, nums: List[int]) -> int:
        l,r=0,len(nums)-1
        ans=nums[-1]
        m=0
        while l<r:
            m=(l+r)//2
            ans=min(ans,nums[m])
            if nums[m]>nums[r]:
                l=m+1
            else:
                r=m-1
        return min(ans,nums[l])
        
