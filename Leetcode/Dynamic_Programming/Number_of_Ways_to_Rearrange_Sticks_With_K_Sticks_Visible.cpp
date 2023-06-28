class Solution {
public:
    const int mod = 1e9 + 7;
    long long solve(int n, int k, vector<vector<long long>>&dp ) {
        if (n < k|| k==0) return 0;
        if(n<=2) return dp[n][k]=1;
        if ( dp[n][k] != -1) return dp[n][k];
        
        long long ans = solve(n-1,k-1,dp);
        ans = (ans + (n-1)*solve(n-1,k,dp))%mod;
        return dp[n][k] = ans;
    }
    
    int rearrangeSticks(int n, int k)
    {
        vector<vector<long long>> dp (n+2 , vector<long long> (k+2,-1));
        return solve(n, k,dp);
    }
};
