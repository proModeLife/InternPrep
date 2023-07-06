class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def backtrack(i, subset, target):
            if target == 0:
                res.append(subset[::])
                return
            if target < 0 or i == len(candidates):
                return

            subset.append(candidates[i])
            backtrack(i + 1, subset, target - candidates[i])
            subset.pop()

            while i + 1 < len(candidates) and candidates[i] == candidates[i + 1]:
                i += 1
            backtrack(i + 1, subset, target)

        backtrack(0, [], target)
        return res
