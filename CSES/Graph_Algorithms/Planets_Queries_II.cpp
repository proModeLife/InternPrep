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

int n,q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your code here
    cin>>n>>q;
    vector<int> next(n);
    vector<vector<int>> before(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;x--;
        next[i]=x;
        before[x].push_back(i);
    }

    vector<int>cycle_id(n,-2);
    vector<map<int,int>> cycles;
    for(int i=0;i<n;i++)
    {
        if(cycle_id[i]!=-2)continue;
        vector<int> path={i};
        int curr=i;
        while(cycle_id[next[curr]]==-2)
        {
            curr=next[curr];
            cycle_id[curr]=-3; // so we dont go infinite looping
            path.push_back(curr);
        }
        map<int,int> cycle;
        bool in_cycle=false;
        for(int p: path)
        {
            in_cycle= in_cycle || p == next[curr];
            if (in_cycle){ cycle[p]=cycle.size(); }
            cycle_id[p] = in_cycle ? cycles.size() : -1;
        }
        cycles.push_back(cycle);
    }

    vector<long long> cyc_dist(n);
    for(int i=0;i<n;i++)
    {
        if(cycle_id[next[i]]==-1 || cycle_id[i]!=-1)continue;
        cyc_dist[i]=1;
        vector<int> stack(before[i]);
        while(!stack.empty())
        {
            int curr= stack.back();
            stack.pop_back();
            cyc_dist[curr]=cyc_dist[next[curr]]+1;
            stack.insert(stack.end(),before[curr].begin(),before[curr].end());
        }
    }

    int Log2= ceil(std::log2(n));
    vector<vector<int>> jump(n,vector<int>(Log2+1));
    for(int i=0;i<n;i++)jump[i][0]=next[i];
    for(int j=1;j<=Log2;j++)
        for(int i=0;i<n;i++)
            jump[i][j]=jump[jump[i][j-1]][j-1];

    auto advance = [&](int start, int distance) {
        for (int i = 0; i <= Log2; i++) {
            if (distance & (1 << i)) {
                start = jump[start][i];
            }
        }
        return start;
    };

    while(q--)
    {
        int u,v;
        cin>>u>>v;u--;v--;
        if(cycle_id[jump[v][Log2]]!=cycle_id[jump[u][Log2]])
        {
            cout<<-1<<endl;
            continue;
        }
        if(cycle_id[u]!=-1 || cycle_id[v]!=-1)
        {
            if(cycle_id[u]!=-1 && cycle_id[v]==-1)
            {
                cout<<-1<<endl;

                continue;
            }
            int dist=cyc_dist[u];
            int cyc_u=advance(u,dist);
            auto cyc= cycles[cycle_id[cyc_u]];
            int ind_u=cyc[cyc_u];
            int ind_v=cyc[v];
            int diff= ind_u <= ind_v ? ind_v-ind_u : cyc.size() + ind_v - ind_u;
            cout<<dist + diff << endl;

        }
        else 
        {
			if (cyc_dist[v] > cyc_dist[u]) {
				cout << -1 << '\n';
				continue;
			}
			int diff = cyc_dist[u] - cyc_dist[v];
			cout << (advance(u, diff) == v ? diff : -1) << '\n';
        }
    }


	return 0;
}
