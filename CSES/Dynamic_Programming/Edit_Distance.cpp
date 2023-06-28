#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>

int edit_distance(const std::string& s1, const std::string& s2, int m, int n, std::vector<std::vector<int>>& dp) {
    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    if (m == 0 || n == 0) {
        return dp[m][n] = m + n;
    }
    if (s1[m - 1] == s2[n - 1]) {
        return dp[m][n] = edit_distance(s1, s2, m - 1, n - 1, dp);
    }
    int ins = edit_distance(s1, s2, m, n - 1, dp);
    int del = edit_distance(s1, s2, m - 1, n, dp);
    int rep = edit_distance(s1, s2, m - 1, n - 1, dp);
    return dp[m][n] = 1 + std::min({ ins, del, rep });
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::vector<std::vector<int>> dp(s1.size() + 1, std::vector<int>(s2.size() + 1, -1));
    for (int i = 0; i <= s1.size(); ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= s2.size(); ++j) {
        dp[0][j] = j;
    }

    int ans = edit_distance(s1, s2, s1.size(), s2.size(), dp);
    std::cout << ans << '\n';

    return 0;
}
