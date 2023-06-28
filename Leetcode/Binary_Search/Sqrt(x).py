class Solution:
    def mySqrt(self, x: int) -> int:
        if x<=1: return x
        l,r=1,x
        while l<=r:
            m=(l+r)//2
            val=m*m
            if val==x: return m
            elif val>x: r=m-1
            else: l=m+1
        return l if l*l<=x else l-1