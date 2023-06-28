class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        chance=True
        for i in range(len(nums)):
            if i == len(nums)-1 or nums[i]<=nums[i+1]:
                continue
            if not chance:
                return False 
            if i==0 or nums[i-1]<=nums[i+1]:
                nums[i]=nums[i+1]
            else:
                nums[i+1]=nums[i]
            chance=False
        return True
