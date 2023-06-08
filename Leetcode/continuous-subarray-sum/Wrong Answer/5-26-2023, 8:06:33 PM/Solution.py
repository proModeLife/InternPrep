// https://leetcode.com/problems/continuous-subarray-sum

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        vals=set()
        curr=0
        for i in nums:
            curr=(i+curr)%k
            if curr in vals:
                return True
            vals.add(curr)
        return False