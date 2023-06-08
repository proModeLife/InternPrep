// https://leetcode.com/problems/contains-duplicate-ii

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        for i in range(len(nums)):
            j=i+1
            while j<len(nums) and (j-i)<=k:
                if nums[i]==nums[j]:
                    return True
                j+=1

        return False
