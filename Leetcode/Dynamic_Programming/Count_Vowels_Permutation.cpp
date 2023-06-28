class Solution {
public:
    const int MOD = 1e9 + 7;
    enum Vowel {A, E, I, O, U};
    vector<vector<long long>> dp;
    long long solve(Vowel vowel, int n) {
        if (n == 1) return 1;
        if (dp[n-1][vowel] != -1) return dp[n-1][vowel];
        
        long long ans = 0;
        switch (vowel) {
            case A:
                ans = solve(E, n-1);
                break;
            case E:
                ans = (solve(A, n-1) + solve(I, n-1))%MOD;
                break;
            case I:
                ans = (solve(A, n-1) + solve(E, n-1) + solve(O, n-1) + solve(U, n-1))%MOD;
                break;
            case O:
                ans = (solve(I, n-1) + solve(U, n-1))%MOD;
                break;
            case U:
                ans = solve(A, n-1);
                break;
        }
        return dp[n-1][vowel] = ans % MOD;
    }
    
    int countVowelPermutation(int n) {
        dp.resize(n, vector<long long>(5, -1));
        long long ans = 0;
        for (int vowel : {A, E, I, O, U}) 
        {
            ans = (ans + solve(static_cast<Vowel>(vowel), n)) % MOD;
        }
        
        return ans;
    }
};
