// https://leetcode.com/problems/asteroid-collision

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        t1=len(asteroids)
        t2=0
        while t1!=t2:
            t2=t1
            i,t1=0,0
            while i+1<len(asteroids):
                if (asteroids[i]>0 and asteroids[i+1]>0) or (asteroids[i]<0 and asteroids[i+1]<0):
                    i+=1
                    t1+=1
                elif abs(asteroids[i])!=abs(asteroids[i+1]):
                    truth= abs(asteroids[i])<abs(asteroids[i+1])
                    asteroids[t1]=asteroids[i+truth]
                    i+=2
                    t1+=1
                else:
                    i+=2
        return asteroids[:t1]