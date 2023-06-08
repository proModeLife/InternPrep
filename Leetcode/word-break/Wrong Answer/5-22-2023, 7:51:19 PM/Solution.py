// https://leetcode.com/problems/word-break

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        truth=[False]*len(s)
        for i in range(len(s)):
            for j in range(i+1,len(s)):
                if not truth[j]and  s[:j+1] in wordDict or (truth[i] and s[i+1:j+1] in wordDict):
                    truth[j]=True

        return truth[len(s)-1]
