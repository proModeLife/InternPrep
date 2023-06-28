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
#include <array>

#define ll long long 
#define ar array
using namespace std;

const int mxN=1e5;
const long long inf=1e18;
vector<ar<ll,2>> adj[mxN];
priority_queue<ll> dist[mxN];
int n,m,k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;a--;b--;
        adj[a].push_back({c,b});
    }
    dist[0].push(0);
    for(int i=0;i<n;i++)
    {
        dist[i].push(inf);
    }
    priority_queue<ar<ll,2>,vector<ar<ll,2>>, greater<ar<ll,2>> > pq;
    pq.push({0,0});

    while(pq.size())
    {
        ar<ll,2> u = pq.top();
        pq.pop();
        if(u[0]>dist[u[1]].top() && dist[u[1]].size()>=k)continue;
        for(ar<ll,2> v: adj[u[1]])
        {
            if(dist[v[1]].top()>u[0]+v[0])
            {
                dist[v[1]].push(u[0]+v[0]);
                if(dist[v[1]].size()==k+1)dist[v[1]].pop();
                pq.push({u[0]+v[0],v[1]});
            }
        }
    }
    vector<long long> ans;

    for(int i=0;i<k;i++){
        ans.push_back(dist[n-1].top());dist[n-1].pop();
    }
    for(int i=k-1;i>=0;i--)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
