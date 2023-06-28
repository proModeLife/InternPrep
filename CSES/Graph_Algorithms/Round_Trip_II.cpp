#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int maxN=1e5;
bool visited [maxN];
bool active[maxN];
int parent [maxN];
vector<int> adj[maxN];

void dfs( int u)
{
    active[u]=true;
    visited[u]=true;
    for(int v: adj[u])
    {
        if(active[v])
        {
            vector<int> ans={u};
            while(u^v){
                u = parent[u];
                ans.push_back(u);
            }
            ans.push_back(ans[0]);
            cout<<ans.size()<<endl;
            for(int a=ans.size()-1;a>=0;a--)
            {
                cout<<ans[a]+1<<" ";
            }
            cout<<endl;
            exit(0);
        }
        else 
        {
            if(!visited[v])
            {
                parent[v]=u;
                dfs(v);
            }
        }
    }
    active[u]=false;
}
 
int main() {
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
    for(int i=0;i<n;i++)
    {
        if(!visited[i]) // unvisited node
        {
            dfs(i);
        }
    }

    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
