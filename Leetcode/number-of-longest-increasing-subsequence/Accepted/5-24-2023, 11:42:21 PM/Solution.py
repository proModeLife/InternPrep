// https://leetcode.com/problems/number-of-longest-increasing-subsequence

from typing import List

class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [(1,1)]*(n+1) # storing how many LIS end at me 
        mxlen, mxcnt = 0, 0
    
        for i in range(n):
            cnt, mx = 1, 1
            for j in range(i-1, -1, -1):
                if nums[j] < nums[i] and dp[j][0] == mx:
                    cnt += dp[j][1]
                elif nums[j] < nums[i] and dp[j][0] > mx:
                    mx = dp[j][0]
                    cnt = dp[j][1]
            dp[i] = (mx+1, cnt)
            mxlen = max(mxlen, mx+1)
        
        for i in range(n):
            if dp[i][0] == mxlen:
                mxcnt += dp[i][1]
        
        return mxcnt