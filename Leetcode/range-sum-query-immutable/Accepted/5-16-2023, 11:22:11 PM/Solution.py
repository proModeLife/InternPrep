// https://leetcode.com/problems/range-sum-query-immutable

class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.prefix_sums = []
        total = 0
        for num in nums:
            total += num
            self.prefix_sums.append(total)

    def sumRange(self, left: int, right: int) -> int:
        if left == 0: # Handle edge case
            return self.prefix_sums[right]
        return self.prefix_sums[right] - self.prefix_sums[left-1]
            


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)