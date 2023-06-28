class Solution {
public:
    int numDistinct(string s, string t) {
        // Get the lengths of the input strings
        size_t n = s.size();
        size_t m = t.size();

        // Create a 2D vector to store the DP values
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(m+1));

        // Initialize the base case: when t is empty, there is exactly one subsequence of s that matches it
        for (size_t i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }

        // Compute the DP values for the remaining cases
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                // If the current characters match, we have two options: either include the current character or not
                dp[i][j] = dp[i+1][j];
                if (s[i] == t[j] && n-i >= m-j) {
                    dp[i][j] += dp[i+1][j+1];
                }
            }
        }

        // Return the final answer
        return dp[0][0];
    }
};
