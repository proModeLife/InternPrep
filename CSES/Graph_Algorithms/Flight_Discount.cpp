
#include <functional>
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
#include <array>
using namespace std;

const int mxN = 1e5;
vector<array<long long, 2>> adj1[mxN];
vector<array<long long, 2>> adj2[mxN];
long long dist1[mxN];
long long dist2[mxN];
int n, m;

void f1(vector<array<long long, 2>> (&adj)[mxN])
{
    memset(dist1, 0x3f, sizeof(dist1));
    dist1[0] = 0;
    priority_queue<array<long long, 2>, vector<array<long long, 2>>,
                   greater<array<long long, 2>>>
        pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        array<long long, 2> u = pq.top();
        pq.pop();
        if (u[0] > dist1[u[1]])
            continue;
        for (array<long long, 2> v : adj[u[1]])
        {
            if (dist1[v[0]] > v[1] + u[0])
            {
                dist1[v[0]] = v[1] + u[0];
                pq.push({v[1] + u[0], v[0]});
            }
        }
    }
}

void f2(vector<array<long long, 2>> (&adj)[mxN])
{
    memset(dist2, 0x3f, sizeof(dist2));
    dist2[n - 1] = 0;
    priority_queue<array<long long, 2>, vector<array<long long, 2>>,
                   greater<array<long long, 2>>>
        pq;
    pq.push({0, n - 1});
    while (!pq.empty())
    {
        array<long long, 2> u = pq.top();
        pq.pop();
        if (u[0] > dist2[u[1]])
            continue;
        for (array<long long, 2> v : adj[u[1]])
        {
            if (dist2[v[0]] > v[1] + u[0])
            {
                dist2[v[0]] = v[1] + u[0];
                pq.push({v[1] + u[0], v[0]});
            }
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
        long long a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        adj1[a].push_back({b, c});
        adj2[b].push_back({a, c});
    }
    f1(adj1);
    f2(adj2);
    long long ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        for (array<long long, 2> v : adj1[i])
        {
            ans=ans>dist1[i]+(long long)floor(v[1]/2)+dist2[v[0]] ? dist1[i]+(long long)floor(v[1]/2)+ dist2[v[0]]: ans;
        }
    }
    cout << ans << endl;

    return 0;
}

