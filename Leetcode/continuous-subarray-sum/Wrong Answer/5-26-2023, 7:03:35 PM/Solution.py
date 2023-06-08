// https://leetcode.com/problems/continuous-subarray-sum

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        val=sum(nums)
        if len(nums)<2 or k >val:
            return False
        elif val%k==0:
            return True
        for p in range(1,len(nums)):
            for i in range(p,len(nums),2*p):
                nums[i]+=nums[i-1]
                if nums[i]%k==0:
                    return True
        return False
