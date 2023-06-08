// https://leetcode.com/problems/valid-palindrome-ii

class Solution:
    def validPalindrome(self, s: str) -> bool:
        if len(s)<=2:
            return True
        t=""
        for i in range(len(s)-1,-1,-1):
            t+=s[i]
        count=0
        for i in range(len(s)):
            if s[i]!=t[i]:
                count+=1
                if count >=3 or count==len(s)-1:
                    return False
        return True
