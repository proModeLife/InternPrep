class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        ans=len(nums)
        for i in range(len(nums)):
            if(nums[i]==val):
                nums[i]=51
                ans-=1
        nums.sort()
        return ans