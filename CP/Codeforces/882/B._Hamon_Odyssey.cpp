
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <iomanip>

using namespace std;

const int maxN = 2e5 + 1;
int arr[maxN];
long long n, ans, opt, curr;

void solve(int idx)
{
    if (idx == n)
    {
        return;
    }
    long long mine = (1LL << 32) - 1;
    for (int i = idx; i < n; i++)
    {
        mine &= arr[i];
        if (mine == opt)
        {
            ans++;
            solve(i + 1);
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        opt = (1LL << 32) - 1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            opt &= arr[i];
        }
        if(opt)
        {
            cout<<1<<endl;
        }
        else
        {
        ans = 0;
        solve(0);
        cout << ans << endl;
        }
    }

    return 0;
}


