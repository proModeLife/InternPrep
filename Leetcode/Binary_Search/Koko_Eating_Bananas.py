class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l,r=1,max(piles)
        ans=max(piles)
        while l<=r:
            m=(l+r)//2
            time=0
            for p in piles:
                time+=ceil(p/m)
                if time > h:
                    break
            if time > h: 
                l=m+1
            else:
                ans=min(ans,m)
                r=m-1
        return ans