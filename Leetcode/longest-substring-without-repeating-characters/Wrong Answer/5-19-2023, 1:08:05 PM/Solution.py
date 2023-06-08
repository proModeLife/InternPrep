// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s)<=1:
            return len(s)
        window={}
        L=0
        res=0
        for R in range(len(s)):
            res=max(res,R-L)
            if s[R] not in window:
                window[s[R]]=R
            else:
                if window[s[R]]< L:
                    window[s[R]]=R
                else:
                    window[s[R]]=R
                    L=R

        return res
