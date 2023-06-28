#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <array>

using namespace std;

const int mxN = 500;
long long d[mxN][mxN];
int n, m, q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    memset(d,0x3f, sizeof(d));
    for (int i = 0; i < m; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b] = min(d[a][b],c);
        d[b][a] = min(d[b][a],c);
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            d[i][i]=0;
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (d[a-1][b-1] < 1e18)
            cout << d[a-1][b-1] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
