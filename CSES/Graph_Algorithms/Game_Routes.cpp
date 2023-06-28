#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9+7;
const int mxN=1e5;
vector<int> adj[mxN];
int child[mxN];
int dist[mxN];

int dfs(int u)
{
    if (dist[u] != -1) return dist[u];
    
    long long val=0;
    for(int v: adj[u])
    {
        (val += dfs(v)) %= mod;
    }
    return dist[u] = val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    
    for (int i = 0; i < n; i++) {
        dist[i] = -1;
    }
    
    dist[n-1]=1;        
    dfs(0);
    
    cout << dist[0] << endl;
    return 0;
}
