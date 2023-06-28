class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i=0
        ans=""
        while(i<min(len(word1),len(word2))):
            ans+=word1[i]+word2[i]
            i+=1
        ans+=word1[i:] + word2[i:]
        return ans
