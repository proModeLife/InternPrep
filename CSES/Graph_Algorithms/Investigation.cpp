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
int n,m;
const int mod = 1e9+7;
const int mxN=1e5;
vector<long long> adj[mxN];
vector< array <long long,2> > adj2[mxN];
int visited[mxN];
long long d[mxN];

long long dfs2(int u)
{
    if(visited[u])return d[u];
    visited[u]=1;
    d[u]=u==n-1?0:1e11;
    for(int v : adj[u])
    {
        if(d[u]>1+dfs2(v))
        {
        (d[u]=1+d[v])%=mod;
        }
    }
    return d[u];
}
long long dfs(int u)
{
    if(d[u])return d[u];
    else d[u]=0;
    for(int v : adj[u])
    {
        (d[u]+=dfs(v))%=mod;
    }
    return d[u];
}

long long dfs3(int u)
{
    if(visited[u])return d[u];
    visited[u]=1;
    d[u]=u==n-1?0:-1e9;
    for(int v : adj[u])
    {
        if(d[u]<1+dfs3(v))(d[u]=1+d[v])%=mod;
    }
    return d[u];
}

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your code here
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;a--;b--;
        adj2[a].push_back({c,b});
    }
    priority_queue<array<long long,2>, vector<array<long long,2>>,greater<array<long long,2>>> q;
    q.push({0,0});
    memset(d, 0x3f, sizeof(d));
    d[0]=0;
    while(!q.empty())
    {
        array<long long,2> u = q.top(); q.pop();
        if(u[0]>d[u[1]])continue;
        for(array<long long,2> v: adj2[u[1]])
        {
            if(d[v[1]]>d[u[1]]+v[0])
            {
                d[v[1]]=d[u[1]]+v[0];
                q.push({d[v[1]],v[1]});
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(array<long long,2> v: adj2[i])
        {
            if(d[v[1]]==d[i]+v[0])
            {
                adj[i].push_back(v[1]);
            }
        }
    }
    cout<< d[n-1]<< " ";

    memset(d,0,sizeof(d));
    d[n-1]=1;
    cout<< dfs(0)<< " ";
    memset(d,0,sizeof(d));
    cout<< dfs2(0)<< " ";
    memset(visited,0,sizeof(visited));
    cout<< dfs3(0)<< endl;

	return 0;
}
