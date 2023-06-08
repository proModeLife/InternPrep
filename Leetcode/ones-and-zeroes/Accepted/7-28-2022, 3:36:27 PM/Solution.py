// https://leetcode.com/problems/ones-and-zeroes

class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        k=len(strs)
        dp=[[[-1 for i in range(n+1)] for j in range(m+1)] for l in range(k)]
        dp[0][0][0]=0
        a=0
        b=0
        for j in strs[0]:
            if j=='0':
                a+=1
            else:
                b+=1
        if a<=m and b<=n:
            dp[0][a][b]=1
        for i in range(1,len(strs)):
            a=0
            b=0
            for j in strs[i]:
                if j=='0':
                    a+=1
                else:
                    b+=1
            for j in range(len(dp[i-1])):
                for l in range(len(dp[i-1][j])):
                    if dp[i-1][j][l]!=-1:
                        dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l])
                        if j+a<=m and l+b<=n:
                            dp[i][j+a][l+b]=max(dp[i][j+a][l+b],dp[i-1][j][l]+1)
        ans=0
        for i in range(len(dp[-1])):
            for j in range(len(dp[-1][i])):
                ans=max(ans,dp[-1][i][j])
        # print(dp)
        return ans
        