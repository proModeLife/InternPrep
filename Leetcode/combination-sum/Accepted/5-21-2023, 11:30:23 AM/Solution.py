// https://leetcode.com/problems/combination-sum

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans=[]
        def helper(ind,candidates,target,curr,ans):
            if target==0:
                ans.append(curr)
                return
            if ind==len(candidates) or target<0:
                return 
            helper(ind,candidates,target-candidates[ind],curr+[candidates[ind]],ans)
            helper(ind+1,candidates,target,curr,ans)
            return
        curr=[]
        helper(0,candidates,target,curr,ans)
        return ans


