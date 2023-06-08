// https://leetcode.com/problems/can-place-flowers

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        bools = [True]*len(flowerbed)
        if flowerbed[0]==1:
            bools[0]=False
            if len(flowerbed)>1:
                bools[1]=False
        if flowerbed[-1] == 1:
            bools[-1]=False
            if len(flowerbed)>1:
                bools[-2]=False
        for i in range(1,len(flowerbed)-1):
            if flowerbed[i]==1:
                bools[i-1]= False
                bools[i]= False
                bools[i+1]= False
        for i in range(len(bools)):
            if n==0: 
                return True
            if bools[i]==True:
                n-=1
                if i < len(bools)-1 :
                    bools[i+1]=False
        return n==0



