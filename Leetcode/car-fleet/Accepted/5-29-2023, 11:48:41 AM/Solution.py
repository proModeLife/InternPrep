// https://leetcode.com/problems/car-fleet

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:

        for i in range(len(position)):
            position[i]= [position[i],speed[i]]
        position.sort()
        for i in range(len(position)):
            position[i]=(target-position[i][0])/position[i][1]
        i=len(position)-1
        ans=0
        while i>=0:
            curr=position[i]
            ans+=1
            i-=1
            while i>=0 and position[i]<=curr:
                i-=1
            
        return ans
