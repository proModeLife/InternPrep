// https://leetcode.com/problems/combination-sum-iv

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        count={0:1}

        for t in range(1,target+1):
            count[t]=0
            for n in nums:
                count[t]+=count.get(t-n,0)
        return count[target]
