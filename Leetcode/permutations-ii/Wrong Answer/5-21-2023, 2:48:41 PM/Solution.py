// https://leetcode.com/problems/permutations-ii

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res=[]
        nums.sort()
        def backtrack(ind):
            if ind==len(nums):
                res.append(nums.copy())
                return
            for i in range(ind,len(nums)):
                if i > ind and nums[ind] == nums[i]:
                    continue
                nums[i],nums[ind]=nums[ind],nums[i]
                backtrack(ind+1)
                nums[i],nums[ind]=nums[ind],nums[i]
            return
        backtrack(0)
        return res