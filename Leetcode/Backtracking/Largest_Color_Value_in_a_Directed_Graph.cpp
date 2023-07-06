
class Solution {
public:
    int n, ans = 0;
    vector<bool> visited, active;
    vector<vector<int>> counts, adj;
    bool cycle = false;

    void dfs(int i, string& colors) {
        if (cycle) return;
        active[i] = true;
        visited[i] = true;
        for (int j : adj[i]) {
            if (active[j]) {
                cycle = true;
                return;
            }
            if (!visited[j]) dfs(j, colors);
            for (int k = 0; k < 26; k++) {
                counts[i][k] = max(counts[i][k], counts[j][k]);
            }
        }
        counts[i][colors[i] - 'a']++;
        for (int k = 0; k < 26; k++) {
            ans = max(counts[i][k], ans);
        }
        active[i] = false;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n = colors.size();
        visited.resize(n);
        active.resize(n);
        adj.resize(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        counts.resize(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs(i, colors);
        }
        if (cycle) return -1;
        return ans;
    }
};
