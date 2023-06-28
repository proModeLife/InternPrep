#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> g(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b, --a, --b;
    g[a].push_back(b), g[b].push_back(a);
  }
  vector<int> p(K), h(K);
  for (int i = 0; i < K; i++) cin >> p[i] >> h[i], p[i]--;

  vector<int> d(N, -1);
  priority_queue<pair<int, int>> Q;

  auto add = [&](int v, int x) {
    if (d[v] < x) Q.emplace(d[v] = x, v);
  };
  for (int i = 0; i < K; i++) add(p[i], h[i]);
  while (Q.size()) {
    auto [x, v] = Q.top();
    Q.pop();
    if (d[v] != x) continue;
    for (auto& u : g[v]) add(u, d[v] - 1);
  }
  vector<int> ans;
  for (int i = 0; i < N; i++)
    if (d[i] >= 0) ans.push_back(i + 1);

  cout << ans.size() << "\n";
  for (int i = 0; i < (int)ans.size(); i++)
    cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
}
