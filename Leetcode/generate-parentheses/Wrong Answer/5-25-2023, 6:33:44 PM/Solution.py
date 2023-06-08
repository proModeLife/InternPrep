// https://leetcode.com/problems/generate-parentheses

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n==1:
            return ["()"]
        else:
            lst= self.generateParenthesis(n-1)
            ans=[]
            for elem in lst:
                ans.append('('+elem+')')
                ans.append("()"+elem)
                if "()"+elem != elem+"()":
                    ans.append(elem+"()")
            return ans
