// https://leetcode.com/problems/sort-an-array

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        if not nums:
            return None
        if len(nums) == 1:
            return [nums[0]]
        a = self.sortArray(nums[0:len(nums)//2])
        b = self.sortArray(nums[len(nums)//2:])
        i, j = 0, 0
        ans = []
        while i < len(a) and j < len(b):
            if a[i] < b[j]:
                ans.append(a[i])
                i += 1
            else:
                ans.append(b[j])
                j += 1
        while i < len(a):
            ans.append(a[i])
            i += 1
        while j < len(b):
            ans.append(b[j])
            j += 1
        return ans