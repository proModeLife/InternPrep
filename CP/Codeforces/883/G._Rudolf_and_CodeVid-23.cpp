
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
int get() {
    string s; cin >> s;
    int now = 0;
    for (int i = 0; i < s.length(); ++i) if (s[i] == '1') {
        now |= 1 << i;
    }
    return now;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) 
    {
        int n, m;
        cin >> n >> m;
        int start= get();
        int full = (1<<n)-1;
        vector<vector<pair<int,int>>> adj(1<<n);
        for (int i = 0; i < m; i++) 
        {
            int d;
            cin>>d;
            int h=get(),s=get();
            for(int mask=0;mask<(1<<n);mask++)
                adj[mask].push_back({d,(mask&(full^h )|s)});
        }
        vector<int> dist ((1<<n),(1<<30));
        dist[start]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,start});
        while(pq.size())
        {
            pair<int,int> u = pq.top();pq.pop();
            if(u.first>dist[u.second])continue;
            for(pair<int,int> v: adj[u.second])
            {
                if(u.first+v.first<dist[v.second])
                {
                    dist[v.second]=u.first+v.first;
                    pq.push({dist[v.second],v.second});
                }
            }
        }
        if(dist[0]==(1<<30))cout<<"-1"<<endl;
        else cout<<dist[0]<<endl;

    }

    return 0;
}
