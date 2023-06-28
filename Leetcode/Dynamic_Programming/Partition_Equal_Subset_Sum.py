from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # Calculate the target sum
        target = sum(nums)
        if target % 2 == 1:
            # If the sum is odd, it cannot be partitioned into two equal subsets
            return False
        else:
            target //= 2
        
        # Initialize the dynamic programming set with 0
        dp = set()
        dp.add(0)
        
        # Sort the input list
        nums.sort()
        
        # Initialize the left and right pointers
        left, right = 0, len(nums) - 1
        
        # Loop until the pointers meet
        while left < right:
            # Initialize the next dynamic programming set
            next_dp = set()
            
            # Iterate through the current dynamic programming set
            for t in dp:
                # Check if the sum can be reached by adding the current number to# the right pointer
                if t + nums[right] == target:
                    return True
                next_dp.add(t + nums[right])
                next_dp.add(t)
            
            # Update the dynamic programming set
            dp = set()
            for t in next_dp:
                # Check if the sum can be reached by adding the current number to the left pointer
                if t + nums[left] == target:
                    return True
                dp.add(t + nums[left])
                dp.add(t)
            
            # Move the pointers
            left += 1
            right -= 1
        
        # If the pointers meet, check if the remaining number can reach the target sum
        if left == right:
            for t in dp:
                if t + nums[right] == target:
                    return True
        
        # If no subset can be partitioned into two equal subsets, return False
        return False