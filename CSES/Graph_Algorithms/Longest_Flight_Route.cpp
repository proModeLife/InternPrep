#include <cstring>
#include <iostream>
#include <ostream>
#include <vector>
#include <stack>

using namespace std;
const int mxN=1e5;
long long dist[mxN];
vector<int> adj[mxN];
int child [mxN];
int dfs(int u)
{
    if (dist[u])return dist[u];
    long long val=-1e11;
    for(int v: adj[u])
    {
        dist[v]=dfs(v);
        if(dist[v]>val)
        {
            val=dist[v];
            child[u]=v;
        }
    }
    return dist[u]=val+1;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    memset(dist, (long long)-1e11, sizeof(dist));
    dist[n-1]=1;
    if(dfs(0)>0)
    {
        cout<<dist[0]<<endl;
        int u=0;
        while(child[u])
        {
            cout<<u+1<<" ";
            u=child[u];
        }
        cout<<n<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
