class Solution {
public:
    long long solve(vector<vector<int>>& piles,vector<vector<long long>>& dp, int idx, int k)
    {
        if (k == 0 || idx==piles.size()) return 0;
        if (dp[idx][k] != -1) return dp[idx][k];
        long long ret = solve(piles,dp,idx+1,k);
        long long sum=0;
        int limit = min((int)piles[idx].size(),k);
        for( int i=0;i<limit;i++)
        {
            sum+=piles[idx][i];
            ret=max(ret,solve(piles,dp,idx+1,k-i-1)+sum);
        }
        return dp[idx][k] = ret;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        vector<vector<long long>> dp(piles.size()+1,vector<long long>(k+1,-1));
        return solve(piles, dp,0, k);
    }
};
