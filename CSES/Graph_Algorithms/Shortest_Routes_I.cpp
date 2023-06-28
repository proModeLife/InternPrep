#include <climits>
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

#define ll long long 
#define ar array
using namespace std;

const int mxN=1e5;
vector<ar<ll,2>> adj[mxN];
ll dist[mxN];
int n,m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;a--;b--;
        adj[a].push_back({c,b});
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[0]=0;
    priority_queue<ar<ll,2>,vector<ar<ll,2>>, greater<ar<ll,2>> > pq;
    pq.push({0,0});

    while(pq.size())
    {
        ar<ll,2> u = pq.top();
        pq.pop();
        if(u[0]>dist[u[1]])continue;
        for(ar<ll,2> v: adj[u[1]])
        {
            if(dist[v[1]]>u[0]+v[0])
            {
                dist[v[1]]=u[0]+v[0];
                pq.push({dist[v[1]],v[1]});
            }
        }
    }

    for(int i=0;i<n;i++)cout<<dist[i]<<" ";
    cout<<endl;
    return 0;
}
