#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int maxN=1e5;
bool visited [maxN];
bool active[maxN];
vector<int> ans;
vector<int> adj[maxN];

void dfs( int u)
{
    active[u]=true;
    visited[u]=true;
    for(int v: adj[u])
    {
        if(active[v])
        {
            cout<<"IMPOSSIBLE"<<endl;
            exit(0);
        }
        else 
        {
            if(!visited[v])
            {
                dfs(v);
            }
        }
    }
    active[u]=false;
    ans.push_back(u);
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

    reverse(ans.begin(),ans.end());
    for(auto it:ans)cout<<it+1<<" ";
    cout<<endl;
    return 0;
}
