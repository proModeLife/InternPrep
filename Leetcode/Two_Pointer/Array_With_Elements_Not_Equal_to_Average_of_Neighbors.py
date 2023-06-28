class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        for i in range(1, len(nums), 2):
            if nums[i] < nums[i - 1]:
                tmp = nums[i]
                nums[i] = nums[i - 1]
                nums[i - 1] = tmp
            if i != len(nums) - 1 and nums[i] < nums[i + 1]:
                tmp = nums[i]
                nums[i] = nums[i + 1]
                nums[i + 1] = tmp
        return nums
