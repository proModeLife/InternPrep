// https://leetcode.com/problems/house-robber

class Solution:
    def rob(self, nums: List[int]) -> int:
        rob_1,rob_2=0,0
        for n in nums:
            choice=max(n+rob_1,rob_2)
            rob_1=rob_2
            rob_2=choice
        return rob_2