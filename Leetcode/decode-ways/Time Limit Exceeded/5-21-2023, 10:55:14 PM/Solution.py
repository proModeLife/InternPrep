// https://leetcode.com/problems/decode-ways

class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0]=='0':
            return 0
        for i in range(1,len(s)):
            if s[i]=='0' and s[i-1]=='0':
                return 0
        ans=0
        def helper(ind):
            nonlocal ans
            if ind==len(s):
                ans+=1
                return
            if ord(s[ind])>ord('0') and ord(s[ind])<=ord('9'):
                helper(ind+1)
            if ind+1<len(s) and int(s[ind]+s[ind+1])<=26 and int(s[ind]+s[ind+1])>9:
                helper(ind+2)
            return
        helper(0)
        return ans

            
