// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        def max_count(amap):
            ans=-1
            for i in amap:
                ans=max(amap[i],ans)
            return ans
        words= {}
        maxc=-1
        L=0
        for R in range(len(s)):
            val=words.get(s[R],0)
            words[s[R]]=val+1
            while k<=R-L-max_count(words):
                words[s[L]]-=1
                L+=1
            maxc=max(R-L+1,maxc)
        return maxc




