class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        if k== len(nums):
            return nums[-1]-nums[0]
        i=0
        ans=nums[k-1]-nums[0]
        while i+k-1<len(nums):
            ans=min(ans,nums[i+k-1]-nums[i])
            i+=1
        return ans
