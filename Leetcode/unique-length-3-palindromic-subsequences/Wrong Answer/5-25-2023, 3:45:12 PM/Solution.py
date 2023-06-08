// https://leetcode.com/problems/unique-length-3-palindromic-subsequences

class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        map1={}
        ans=set()
        for i in range(len(s)):
            if map1.get(s[i],-1)==-1:
                map1[s[i]]=i
            elif map1[s[i]]<i-1:
                j=map1[s[i]] 
                for k in range(j+1,i):
                    ans.add(s[j]+s[k]+s[i])
                map1[s[i]]=i
            
        return len(ans)