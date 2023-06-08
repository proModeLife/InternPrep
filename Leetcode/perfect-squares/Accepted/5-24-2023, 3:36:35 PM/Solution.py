// https://leetcode.com/problems/perfect-squares

class Solution:
    def numSquares(self, n: int) -> int:
        if n<=3:
            return n
        
        squares=[]
        dp = [n]*(n+1)
        dp[0],dp[1],dp[2],dp[3]=0,1,2,3

        for i in range(n):
            sq=i*i
            if sq>n:
                break
            elif sq==n:
                return 1
            else:
                dp[sq]=1
                squares.append(sq)
        
        for i in range(4,n+1):
            j=0
            while j<len(squares) and squares[j]<=i:
                dp[i]=min(dp[i],1+dp[i-squares[j]])
                j+=1

        return dp[n]

