#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void testcase() {
    int n, m, k;
    cin >> n >> m >> k;

    // Initialize an array to keep track of the minimum distance required to reach each house in the city
    vector<int> viz(n + 1, 0);

    // Read in the starting locations of the K mail carriers and the maximum distance they can travel
    vector<int> x(k + 1);
    vector<int> d(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> d[i];
        viz[x[i]] = min(-d[i], viz[x[i]]);
    }

    // Read in the edges of the graph representing the city
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Use a priority queue to keep track of the mail carriers and their remaining distance
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    for (int i = 1; i <= k; i++) {
        q.push(make_pair(-d[i], x[i]));
    }

    // Update the minimum distance required to reach all houses that can be reached from each mail carrier's current location within their remaining distance
    while (!q.empty()) {
        int curr = q.top().second;
        int dist = q.top().first;
        q.pop();
        if (viz[curr] != dist) {
            continue;
        }
        for (auto next : g[curr]) {
            if (viz[curr] + 1 < viz[next]) {
                viz[next] = viz[curr] + 1;
                q.push(make_pair(viz[next], next));
            }
        }
    }

    // Check if all houses in the city have a positive minimum distance required to reach them
    bool possible = true;
    for (int i = 1; i <= n; i++) {
        if (viz[i] == 0) {
            possible = false;
            break;
        }
    }

    // Output the result
    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}