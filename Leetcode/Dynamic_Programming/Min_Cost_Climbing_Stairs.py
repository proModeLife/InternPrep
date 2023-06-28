class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n=len(cost)
        ans=cost
        for i in range(2,n):
            ans[i]+=min(ans[i-1],ans[i-2])
        return min(ans[n-1],ans[n-2])
