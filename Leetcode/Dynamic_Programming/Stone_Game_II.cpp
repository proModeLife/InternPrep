class Solution {
public:
    long long solve(int idx, vector<int>& piles, int m, int chance,
        vector<vector<vector<long long>>>& dp)
    {
        if (dp[idx][m][chance] != -1) return dp[idx][m][chance];
        if (idx == piles.size()) return 0;
        
        long long sum = 0;
        long long res = chance ? 100000000000 : -1;
        
        for (int i = idx; i <= min(idx + 2 * m - 1, (int)piles.size() - 1); i++)
        {
            sum += piles[i];
            if (chance)
            {
                res = min(res, solve(i + 1, piles, max(i - idx + 1, m), 0, dp));
            }
            else
            {
                res = max(res, sum + solve(i + 1, piles, max(i - idx + 1, m), 1, dp));
            }
        }
        
        return dp[idx][m][chance] = res;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(2 * n + 1, vector<long long>(2, -1)));
        return solve(0, piles, 1, 0, dp);
    }
};
