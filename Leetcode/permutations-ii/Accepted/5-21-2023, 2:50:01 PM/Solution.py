// https://leetcode.com/problems/permutations-ii

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = []
        visited = set()

        def backtrack(perm):
            if len(perm) == len(nums):
                ans.append(perm[:])
                return

            for i in range(len(nums)):
                if i in visited or (i > 0 and nums[i] == nums[i-1] and i-1 not in visited):
                    continue
                visited.add(i)
                perm.append(nums[i])
                backtrack(perm)
                perm.pop()
                visited.remove(i)

        nums.sort()
        backtrack([])
        return ans