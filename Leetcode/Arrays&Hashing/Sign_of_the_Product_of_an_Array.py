class Solution:
    def arraySign(self, nums: List[int]) -> int:
        ans=1
        for i in nums:
            if not i: return 0
            ans*= 1 - 2*int(i<0)
        return ans
