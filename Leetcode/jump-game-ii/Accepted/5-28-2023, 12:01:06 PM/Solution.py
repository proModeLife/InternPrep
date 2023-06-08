// https://leetcode.com/problems/jump-game-ii

class Solution:
    def jump(self, nums: List[int]) -> int:
        n=len(nums)
        dp=[n]*n
        dp[n-1]=0
        for i in range(n-2,-1,-1):
            reach= min(n-1,i+nums[i])
            for j in range(i+1,reach+1):
                dp[i]=min(dp[i],1+dp[j])
        return dp[0]

