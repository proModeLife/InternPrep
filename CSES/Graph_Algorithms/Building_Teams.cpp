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
    vector<int> groups(n,0);
    for(int i=0;i<n;i++)
    {
        if(groups[i])continue;
        queue<int> q;
        q.push(i);
        groups[i]=1;

        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto v: adj[u])
            {
                if(!groups[v])
                {
                    groups[v]=3-groups[u];
                    q.push(v);
                }
                else
                {
                    if(groups[v]==groups[u])
                    {
                        cout<<"IMPOSSIBLE"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)cout<<groups[i]<<" ";
    cout<<endl;
    return 0;
}
