// https://leetcode.com/problems/repeated-dna-sequences

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        if len(s)<=10:
            return None
        store = defaultdict(int)
        for i in range(9,len(s)):
            store[s[i-10:i]]+=1
        ans=[]
        for i in store:
            if store[i]>1:
                ans.append(i)
        return ans

