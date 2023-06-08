// https://leetcode.com/problems/word-break

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        truth=[False]*len(s)
        for i in range(len(s)):
            if not truth[i] and s[:i+1] in wordDict:
                truth[i]=True
            j=i
            while j >=0 and not truth[i]:
                if truth[j] and  s[j+1:i+1] in wordDict:
                    truth[i]=True
                j-=1
                

        return truth[len(s)-1]
