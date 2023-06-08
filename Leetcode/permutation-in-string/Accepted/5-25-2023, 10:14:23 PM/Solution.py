// https://leetcode.com/problems/permutation-in-string

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s2)<len(s1):
            return False
        s1counter={}
        for i in s1:
            if i not in s1counter:
                s1counter[i]=0
            s1counter[i]+=1
        i,j=0,0
        counter={}
        while j-i<len(s1):
            if s2[j] not in counter:
                counter[s2[j]]=0
            counter[s2[j]]+=1
            j+=1
        if s1counter==counter:
            return True
        while j<len(s2):
            if s2[j] not in counter:
                counter[s2[j]] = 0
            counter[s2[j]] += 1

            if counter[s2[i]] == 1:
                del counter[s2[i]]
            else:
                counter[s2[i]] -= 1
            i += 1

            if s1counter == counter:
                return True
            j += 1
        return False