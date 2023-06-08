// https://leetcode.com/problems/permutations

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans=[]
        def helper(ind):
            if ind == len(nums):
                ans.append(nums.copy()) # Use the copy method to append the copy of the list
                return 
            for i in range(ind,len(nums)):
                nums[ind],nums[i]=nums[i],nums[ind]
                helper(ind+1)
                nums[ind],nums[i]=nums[i],nums[ind]
            return
        helper(0)
        return ans