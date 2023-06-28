#include <iostream>
#include <iterator>
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
vector<int> adj[mxN],adjT[mxN], adj2[mxN];
long long values[mxN], sums[mxN], dp[mxN];
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
    visited[u]=false;
    group[u]=groupNumber;
    for(int v: adjT[u])
    {
        if(visited[v])
            dfs2(v);
    }
    sums[groupNumber]+=values[u];
}
void dfs3(int u)
{
    visited[u]=true;
    for(int v: adj2[u])
    {
        if(!visited[v]) dfs3(v);
        dp[u]=max(dp[u],dp[v]);
    }
    dp[u]+=sums[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code here
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>values[i];
        sums[i]=0;
    }
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
    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if (visited[u]) {
            groupNumber=u;
            dfs2(u);
        }
    }
    for(int i=0;i<n;i++)
        for(int j:adj[i])
            if(group[i]!=group[j])
                adj2[group[i]].push_back(group[j]);
    long long ans=0;
    for(int i=0;i<n;i++)
        if(group[i]==i && !visited[i]){
            dfs3(i); ans=max(ans,dp[i]);
        }
    cout<<ans<<endl;;
    return 0;
}
