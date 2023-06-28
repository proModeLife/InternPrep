#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <array>

using namespace std;

const int mxN = 2501;
const int mxM = 5000;
const long long inf = 0xc0;
long long d[mxN];
int parent[mxN];
bool visited[mxN];

int n, m;

vector<pair<long long, long long>> adj[mxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b, w}); 
    }
    memset(d,0xc0,sizeof(d));
    memset(parent, -1, sizeof(parent))  ;
    d[0] = 0;
    
    for (int i = 0; i <n; i++)
    {
        for(int j=0;j<n;j++)
        {
            for (auto e : adj[j])
            {
                int k = e.first;
                long long w = e.second;
                if (d[j] + w< d[k])
                {
                    d[k] = d[j] + w;
                    parent[k]=j;
                    if(i==n-1)
                    {
                        cout<<"YES\n";
                        while(!visited[j])
                        {
                            visited[j]=true;
                            j=parent[j];
                        }
                        int st=j;
                        vector<int> ans;
                        ans.push_back(j);
                        j=parent[j];
                        while(st^j)
                        {
                            ans.push_back(j);
                            j=parent[j];
                        }
                        ans.push_back(j);
                        for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]+1<<" ";
                        cout<<endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "NO" << "\n";

    return 0;
}
