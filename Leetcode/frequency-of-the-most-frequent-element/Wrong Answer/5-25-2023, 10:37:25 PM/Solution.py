// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        max_frequency = 1
        i = 0
        for j in range(1, len(nums)):
            # calculate the difference between nums[j] and nums[j-1]
            diff = nums[j] - nums[j-1]
            # check if k is enough to make all the numbers between i and j equal to nums[j]
            k -= diff * (j - i)
            while k < 0 and i < j:
                # move the left pointer and add the value back to k
                k += nums[i+1] - nums[i]
                i += 1
            # update the maximum frequency
            max_frequency = max(max_frequency, j - i + 1)
        return max_frequency