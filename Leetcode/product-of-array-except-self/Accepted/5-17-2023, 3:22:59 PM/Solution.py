// https://leetcode.com/problems/product-of-array-except-self

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix=[0]*len(nums)
        suffix=[0]*len(nums)
        mult=1
        for i in range(len(nums)):
            mult*=nums[i]
            prefix[i]=mult
        mult=1
        for i in range(len(nums)-1,-1,-1):
            mult*=nums[i]
            suffix[i]=mult
        ans=[0]*len(nums)
        ans[0]=suffix[1]
        ans[len(nums)-1]=prefix[len(nums)-2]
        for i in range(1,len(nums)-1):
            ans[i]=prefix[i-1]*suffix[i+1]
        return ans
