// https://leetcode.com/problems/search-insert-position

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        m=0
        while l <= r:
            m = l + ((r - l) // 2)  # (l + r) // 2 can lead to overflow
            if nums[m] > target:
                if m==0 or nums[m-1]<target:
                    return m
                r = m - 1
            elif nums[m] < target:
                if m==len(nums)-1 or nums[m+1]>target:
                    return m+1
                l = m + 1
            else:
                return m
        return m