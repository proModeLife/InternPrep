// https://leetcode.com/problems/combinations

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans=[]
        def helper(curr,count):
            if len(curr)==k:
                ans.append(curr)
                return
            if count==n+1:
                return 
            helper(curr+[count],count+1)
            helper(curr,count+1)
            return
        curr=[]
        helper(curr,1)
        return ans
             