// https://leetcode.com/problems/sliding-window-maximum

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums:
            return []
        
        n = len(nums)
        if k == 1:
            return nums
        
        # Initialize deque and result list
        dq = deque()
        result = []
        
        for i in range(n):
            # Remove index of element outside the current sliding window
            if dq and dq[0] <= i - k:
                dq.popleft()
            
            # Remove indices of elements smaller than the current element
            while dq and nums[dq[-1]] <= nums[i]:
                dq.pop()
            
            # Add current index to the deque
            dq.append(i)
            
            # Add maximum element for the current sliding window to the result list
            if i >= k - 1:
                result.append(nums[dq[0]])
        
        return result