#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <array>

using namespace std;

const int mxN = 2502;
const int mxM = 5000;
const long long inf = 0xc0;
long long d[mxN];
bool visited[mxN];
bool visited2[mxN];
int n, m;

vector<pair<int, long long>> adj[mxN];
vector<int> backward_adj[mxN];

void dfs(int u)
{
    visited[u] = true;
    for (int v : backward_adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}
void dfs2(int u)
{
    visited2[u] = true;
    for (pair<int,long long> v : adj[u])
    {
        if (!visited2[v.first])
        {
            dfs2(v.first);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b, w}); // negate the weight
        backward_adj[b].push_back(a);
    }
    
    memset(d,0xc0,sizeof(d));
    d[0] = 0;
    dfs2(0);
    dfs(n-1);
    for (int i = 0; i <2*n; i++)
    {
        for(int j=0;j<n;j++)
        {
            for (auto e : adj[j])
            {
                int k = e.first;
                long long w = e.second;
                if (d[j] + w > d[k])
                {
                    if (visited[k] && visited2[k] && i>=n-1)
                    {
                        cout << "-1\n";
                        return 0;
                    }
                    d[k] = d[j] + w;
                }
            }
        }
    }

    cout << d[n - 1] << "\n";

    return 0;
}
