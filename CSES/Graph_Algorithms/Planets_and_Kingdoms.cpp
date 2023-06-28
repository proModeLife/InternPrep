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

using namespace std;

const int mxN =1e5;
stack<int> stk;
vector<int> adj[mxN],adjT[mxN];
int group[mxN];
int groupNumber;
bool visited[mxN];
int n,m;

void dfs1(int u)
{
    visited[u]=true;
    for(int v: adj[u])
    {
        if(!visited[v])
            dfs1(v);
    }
    stk.push(u);
}

void dfs2(int u)
{
    visited[u]=true;
    group[u]=groupNumber;
    for(int v: adjT[u])
    {
        if(!visited[v])
            dfs2(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code here
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;a--;b--;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }
    for(int i=0;i<n;i++)
        if(!visited[i])
            dfs1(i);
    groupNumber=1;
    memset(visited, false, sizeof(visited));
    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if (!visited[u]) {
            dfs2(u);
            groupNumber++;
        }
    }
    cout<<groupNumber-1<<endl;
    for(int i=0;i<n;i++)cout<<group[i]<<" ";
    cout<<endl;

    return 0;
}
