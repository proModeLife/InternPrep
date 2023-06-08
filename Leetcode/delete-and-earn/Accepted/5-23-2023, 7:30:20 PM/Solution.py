// https://leetcode.com/problems/delete-and-earn

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        nums.sort()
        nums2=[]
        i=0
        while i < len(nums):
            num=nums[i]
            add = 0
            while i<len(nums) and nums[i]==num:
                i+=1
                add+=num
            nums2.append((num,add))

        dp=[0]*(len(nums2)+1)
        dp[-2]=nums2[-1][1]
        for i in range(len(nums2)-2,-1,-1):
            if nums2[i+1][0] == nums2[i][0]+1:
                dp[i]=max(dp[i+1],nums2[i][1]+dp[i+2])
            else:
                dp[i]=max(dp[i+1]+nums2[i][1],nums2[i][1]+dp[i+2])

        return dp[0]

        