class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l,r=0,len(nums)-1
        while l<r:
            m=l+(r-l)//2
            if m%2: m-=1
            if nums[m]==nums[m+1]:l=m+2
            else:r=m
        return nums[l]

        while l<=r:
            m=l+(r-l)//2
            if ((m==0 or nums[m-1]!=nums[m]) and (m==len(nums)-1 or nums[m]!=nums[m+1])):
                return nums[m]
            leftSize= m-1 if nums[m-1] == nums[m] else m
            if leftSize%2==1: r=m-1
            else: l = m+1 
        