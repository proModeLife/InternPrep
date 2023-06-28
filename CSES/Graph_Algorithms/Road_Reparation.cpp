#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<long long> dist(n, INF);
    vector<bool> visited(n, false);
    dist[0] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(0, 0);

    long long mst_weight = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        mst_weight += dist[u];

        for (auto [v, w] : adj[u]) {
            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.emplace(w, v);
            }
        }
    }

    for(int i=0;i<n;i++)
        if(!visited[i])
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    cout << mst_weight << endl;

    return 0;
}
