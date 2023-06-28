#include <iostream>
#include <ostream>
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

const int mxN=1e5;
bool visited[mxN];

void dfs(int u,vector<vector<int>>& adj)
{
    visited[u]=true;
    for(int v:adj[u])
        if(!visited[v])dfs(v,adj);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your code here
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n), adjT(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }
    dfs(0,adj);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            cout<<"NO\n"<<1<<" "<<i+1<<endl;
            return 0;
        }
        visited[i]=false;
    }
    dfs(0,adjT);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            cout<<"NO\n"<<i+1<<" "<<1<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;


	return 0;
}
