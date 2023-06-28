#include <iostream>
#include <vector>
using namespace std;

const long long int MOD = 1000000007;

long long fastPowerMod(long long base, long long exponent)
{
    long long result = 1;
    base %= MOD;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }

    return result;
}

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ls = 0, l4 = 0, l0 = 0;
    int rs = 0, r4 = 0, r0 = 0;
    for (int i = 0; i < n; i++)
    {
        rs += (str[i] == '*');
        r4 += (str[i] == '4');
        r0 += (str[i] == '0');
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        rs -= (str[i] == '*');
        r4 -= (str[i] == '4');
        r0 -= (str[i] == '0');

        if (str[i] == '0' || str[i] == '*')
        {
            ans += (l4 * r4) % MOD * fastPowerMod(2, rs + ls) % MOD;
            ans %= MOD;

            ans += (l4 * rs) % MOD * fastPowerMod(2, rs + ls - 1) % MOD;
            ans %= MOD;

            ans += (ls * r4) % MOD * fastPowerMod(2, rs + ls - 1) % MOD;
            ans %= MOD;

            ans += (ls * rs) % MOD * fastPowerMod(2, rs + ls - 2) % MOD;
            ans %= MOD;
        }
        ls += (str[i] == '*');
        l4 += (str[i] == '4');
        l0 += (str[i] == '0');
    }
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
