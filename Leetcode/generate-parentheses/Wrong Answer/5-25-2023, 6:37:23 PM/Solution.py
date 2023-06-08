// https://leetcode.com/problems/generate-parentheses

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 1:
            return ["()"]
        else:
            lst = self.generateParenthesis(n - 1)
            ans = set()
            for elem in lst:
                ans.add('(' + elem + ')')
                ans.add(elem + '()')
                ans.add('()' + elem)
            return list(ans)