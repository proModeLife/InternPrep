// https://leetcode.com/problems/subarray-sum-equals-k

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n=len(nums)
        ans=0
        for i in range(n):
            sm=0
            for j in range(i,n):
                sm+=nums[j]
                ans+= sm==k
        return ans