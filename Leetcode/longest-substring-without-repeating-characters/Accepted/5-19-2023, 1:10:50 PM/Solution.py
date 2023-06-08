// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)
        window = {}
        L = 0
        res = 0
        for R in range(len(s)):
            if s[R] in window:
                L = max(L, window[s[R]] + 1)
            res = max(res, R - L + 1)
            window[s[R]] = R
        return res