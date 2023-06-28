class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        leftsum, rightsum = 0,0
        for i in nums:
            rightsum+=i
        for i in range(len(nums)):
            rightsum-=nums[i]
            if leftsum==rightsum:
                return i
            leftsum+=nums[i]
        return -1
