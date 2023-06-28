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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your code here
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<int> parents(n,0);
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(0);
    visited[0]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v: adj[u])
        {
            if(visited[v])continue;
            if(v==n-1)
            {
                vector<int> ans;
                ans.push_back(n);
                while(u!=0)
                {
                    ans.push_back(u+1);
                    u=parents[u];
                }
                ans.push_back(1);
                cout<<ans.size()<<endl;
                for(int i=ans.size()-1;i>=0;i--)
                {
                    cout<<ans[i]<<" ";
                }
                cout<<endl;
                return 0;
            }
            else 
            {
                parents[v]=u;
                q.push(v);
                visited[v]=true;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
