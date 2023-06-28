class Solution {
public:
    long long solve(size_t i, size_t j, string word1, string word2, vector<vector<long long>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        if (word1[i] == word2[j]) return dp[i][j] = solve(i+1, j+1, word1, word2, dp);
        return dp[i][j] = 1 + min(
            solve(i, j+1, word1, word2, dp),
            min(solve(i+1, j, word1, word2, dp), solve(i+1, j+1, word1, word2, dp))
        );
    }
    
    int minDistance(string word1, string word2) {
        size_t n = word1.size();
        size_t m = word2.size();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, -1));
        for( int i=0;i<=n;i++)dp[i][m]=n-i;
        for( int i=0;i<=m;i++)dp[n][i]=m-i;
        return solve(0, 0, word1, word2, dp);
    }
};
