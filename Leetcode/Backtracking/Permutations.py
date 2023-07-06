class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        visited = set()

        def backtrack(perm):
            if len(perm) == len(nums):
                ans.append(perm[:])
                return

            for i in range(len(nums)):
                if i not in visited:
                    visited.add(i)
                    perm.append(nums[i])
                    backtrack(perm)
                    perm.pop()
                    visited.remove(i)

        backtrack([])
        return ans
