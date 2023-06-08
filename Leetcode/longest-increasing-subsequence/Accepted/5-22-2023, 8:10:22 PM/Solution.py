// https://leetcode.com/problems/longest-increasing-subsequence

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp=[1]*len(nums)
        ans=1
        for i in range(len(nums)):
            for j in range(i,-1,-1):
                if nums[j]<nums[i] and dp[i]<=dp[j]:
                    dp[i]=dp[j]+1
                    ans=max(ans,dp[i])
        return ans
        