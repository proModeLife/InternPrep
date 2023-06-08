// https://leetcode.com/problems/is-subsequence

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        found=0
        idx=0
        while found<len(s) and idx<len(t):
            if t[idx]==s[found]:
                found+=1
            idx+=1
        if found==len(s):
            return True
        return False