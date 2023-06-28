
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
#define ll long long
#define ar array 
using namespace std;

const int mxN = 2e5;
ll n, u, LOG = 32;
ll* root, *prev_, *depth, *cycle_id;
ll** up;
bool* vis, *curr;
vector<ll> cycle_size;

ll fast_expo(ll a, ll n, ll x)
{
    ll ans = 1;
    while (n >= 1)
    {
        if (n % 2)
        {
            ans =(ans * a)% x;
            n--;
        }
        else
        {
            a=(a * a)%x;
            n /= 2;
        }
    }
    return ans;
}

void lift_cycle(vector<vector<ll>>& adj, ll cyc, ll a)
{
    ll node = a;
    vector<ll> cycle;

    do
    {
        cycle.push_back(node);
        root[node] = node;
        cycle_id[node] = cyc;
        depth[node] = 0;
        node = prev_[node];

    } while (node != a);

    ll x = cycle.size();
    ll exp_2[LOG];
    cycle_size.push_back(x);

    for (int i = 0; i < LOG; i++)
        exp_2[i] = fast_expo(2, i, x);

    for (int i = 0; i < x; i++)
        for (int j = 0; j < LOG; j++)
            up[cycle[i]][j] = cycle[(i + exp_2[j]) % x];
}

void dfs(vector<vector<ll>>& adj, ll cyc, ll i)
{
    vis[i] = curr[i] = true;
    for (int v : adj[i])
    {
        prev_[v] = i;
        if (!vis[v])
        {
            dfs(adj, cyc, v);
        }
        else
        {
            if (curr[v])
            {
                lift_cycle(adj, cyc, v); // apply binary lifting if we find a cycle
                cyc++;
            }
        }
    }
    curr[i] = false;
}

void dfs_simple(vector<vector<ll>>& adj, ll ver, ll par = -1)
{
    for (ll nbr : adj[ver])
    {
        if (root[nbr] == nbr)
            continue;
        root[nbr] = root[ver];
        depth[nbr] = depth[ver] + 1;
        up[nbr][0] = ver;
        for (ll j = 1; j < LOG; j++)
        {
            up[nbr][j] = up[up[nbr][j - 1]][j - 1];
        }
        dfs_simple(adj, nbr, ver);
    }
}

ll lca(ll u, ll v)
{
    ll diff = depth[u] - depth[v], dist = 0;
    for (ll j = LOG - 1; j >= 0; j--)
    {
        if (1 & (diff >> j))
        {
            u = up[u][j];
            dist += (1ll << j);
        }
    }
    return u == v ? dist : -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code here
    cin >> n;
    vis = new bool[n];
    curr = new bool[n];
    prev_ = new ll[n];
    root = new ll[n]; // root of the tree, if in cycle, then root itself
    depth = new ll[n];
    cycle_id = new ll[n];
    up = new ll*[n];

    for (ll i = 0; i < n; i++)
    {
        root[i] = -1;
        vis[i] = curr[i] = false;
        up[i] = new ll[LOG];
    }

    vector<vector<ll>> adjT(n); // here we will store edges inverted
    for (int i = 0; i < n; i++)
    {
        cin >> u;
        u--;
        adjT[u].push_back(i);
    }
    ll cyc = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        dfs(adjT, cyc, i);  // here we will detect cycles and populate their DP states
    }
    for (int i = 0; i < n; i++)
    {
        if (root[i] == i)
            dfs_simple(adjT, i); // now we will populate DP states for the tree
    }

    for (ll i = 0; i < n; i++)
        cout <<i<<" "<< lca(i, root[i]) << " "<< cycle_size[cycle_id[root[i]]] << "\n";

    cout<<endl;
    return 0;
}
