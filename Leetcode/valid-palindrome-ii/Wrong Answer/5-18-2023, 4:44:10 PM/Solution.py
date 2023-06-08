// https://leetcode.com/problems/valid-palindrome-ii

class Solution:
    def validPalindrome(self, s: str) -> bool:
        if len(s)<=2:
            return True
        # t=""
        # for i in range(len(s)-1,-1,-1):
        #     t+=s[i]
        count=0
        i,j=0,len(s)-1
        while i<j and count<2:
            if s[i]!=s[j]:
                if s[i+1]==s[j]:
                    count+=1
                    i+=1
                    continue
                elif s[j-1]==s[i]:
                    count+=1
                    j-=1
                    continue
                else:
                    return False
            i+=1
            j-=1
        return count<2

