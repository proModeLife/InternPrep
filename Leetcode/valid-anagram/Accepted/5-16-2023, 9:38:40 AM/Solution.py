// https://leetcode.com/problems/valid-anagram

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False 
        arrs=[0]*26
        arrt=[0]*26
        for i in range(len(s)):
            arrs[ord(s[i])-ord('a')]+=1
            arrt[ord(t[i])-ord('a')]+=1
        for i in range(26):
            if arrs[i]!=arrt[i]:
                return False
        return True