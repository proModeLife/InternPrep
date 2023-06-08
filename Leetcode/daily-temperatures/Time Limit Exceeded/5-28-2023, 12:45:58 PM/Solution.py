// https://leetcode.com/problems/daily-temperatures

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans=[0]*len(temperatures)
        for i in range(len(temperatures)):
            curr=0
            for j in range(i+1,len(temperatures)):
                if temperatures[j]>temperatures[i]:
                    ans[i]=j-i
                    break
        return ans
