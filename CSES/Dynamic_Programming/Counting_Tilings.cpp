
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int dp[1001][1 << 11];
const int mod = 1e9 + 7;

void generate_masks(int j, int curr, int next, vector<int> &next_masks) {
    if (j == n) {
        next_masks.push_back(next);
        return;
    }
    if (curr & (1 << j))
        generate_masks(j + 1, curr, next, next_masks);
    else {
        generate_masks(j + 1, curr, next + (1 << j), next_masks);
        if (j + 1 < n && !(curr & (1 << (j + 1)) ))
            generate_masks(j + 2, curr, next, next_masks);
    }
}

long long solve(int i, int mask) {
    if (i == m)
        return mask == 0 ? 1 : 0;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    vector<int> next_masks;
    long long ans = 0;
    generate_masks(0, mask, 0, next_masks);
    for (int next : next_masks) {
        ans = (ans + solve(i + 1, next)) % mod;
    }
    return dp[i][mask] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code here
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << endl;
    return 0;
}
