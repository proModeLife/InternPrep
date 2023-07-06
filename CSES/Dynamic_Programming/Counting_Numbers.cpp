#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long dp[20][10][2][2];


long long countValidIntegers(const string& num, int pos, int prevDigit, int leadingZeros, int isLess) {
    if (pos == num.size())
        return 1;

    if (dp[pos][prevDigit][leadingZeros][isLess] != -1)
        return dp[pos][prevDigit][leadingZeros][isLess];

    int upperLimit = (isLess) ? 9 : ('9' - '0'); // Corrected calculation

    long long count = 0;

    for (int digit = 0; digit <= upperLimit; digit++) {
        if (digit == prevDigit && !leadingZeros)
            continue;

        count += countValidIntegers(num, pos + 1, digit, (leadingZeros && digit == 0), (isLess || digit < upperLimit));
    }

    return dp[pos][prevDigit][leadingZeros][isLess] = count;
}
long long solve(long long a, long long b) {
    if (a == 0)
        return countValidIntegers(to_string(b), 0, -1, 1, 0);
    else
        return countValidIntegers(to_string(b), 0, -1, 1, 0) - countValidIntegers(to_string(a - 1), 0, -1, 1, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    long long a, b;
    cin >> a >> b;

    long long result = solve(a, b);
    cout << result << endl;

    return 0;
}

