// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = 1
        i = 0
        j = 1
        while j < len(nums):
            # Calculate the difference between the current and previous number
            diff = nums[j] - nums[j - 1]
            # Calculate the amount of k needed to make the previous number equal to the current number
            need = diff * (j - i)
            # If k is enough, move the left pointer to the right and update k
            if k >= need:
                k -= need
                ans = max(ans, j - i + 1)
                j += 1
            # If k is not enough, move the left pointer to the right and add back the value to nums
            else:
                k += nums[i] - nums[i - 1]
                i += 1
        return ans