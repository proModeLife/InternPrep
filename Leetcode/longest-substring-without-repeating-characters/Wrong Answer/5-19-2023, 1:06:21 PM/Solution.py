// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        window={}
        L=0
        res=0
        for R in range(len(s)):
            if s[R] not in window:
                window[s[R]]=R
            else:
                if window[s[R]]< L:
                    window[s[R]]=R
                else:
                    window[s[R]]=R
                    res=max(res,R-L)
                    L=R

        return res
