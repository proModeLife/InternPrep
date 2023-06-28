#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int maxN=1e5;
bool visited [maxN];
int parent [maxN];
vector<int> adj[maxN];

void dfs( int u, int p=-1)
{
    parent[u]=p;
    visited[u]=true;
    for(int v: adj[u])
    {
        if(p==v)continue;
        if(visited[v])
        {
            vector<int> ans;
            int u2=u;
            while(u^v){
                ans.push_back(u);
                u = parent[u];
            }
            ans.push_back(v);
            ans.push_back(u2);
            cout<<ans.size()<<endl;
            for(int a=0;a<ans.size();a++)
            {
                cout<<ans[a]+1<<" ";
            }
            cout<<endl;
            exit(0);
        }
        else 
        {
            dfs(v,u);
        }
    }
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
        adj[b-1].push_back(a-1);
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i]) // unvisited node
            dfs(i);
    }

    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
