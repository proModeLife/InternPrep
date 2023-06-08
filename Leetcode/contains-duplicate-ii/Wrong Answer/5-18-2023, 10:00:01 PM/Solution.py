// https://leetcode.com/problems/contains-duplicate-ii

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        for i in range(len(nums)-k):
            for j in range(1,k+1):
                if nums[i]==nums[i+j]:
                    return True
        return False
