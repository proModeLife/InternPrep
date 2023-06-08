// https://leetcode.com/problems/find-the-duplicate-number

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        ans=0
        for i in range(len(nums)):
            ans^=nums[i]
            ans^=i
        return ans