
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans=[]
        def helper(ind,nums,ans,curr):
            if ind == len(nums):
                ans.append(curr)
                return
            helper(ind+1,nums,ans,curr)
            helper(ind+1,nums,ans,curr+[nums[ind]])
            return
        ans=[]
        helper(0,nums,ans,[])
        return ans

