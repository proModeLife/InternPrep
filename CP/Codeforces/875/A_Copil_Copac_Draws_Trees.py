from collections import defaultdict

def solve(n, edges):
    dp = [1] + [0] * (n - 1)
    id = [0] * (n+1)
    adj = defaultdict(list)
    for i, (u, v) in enumerate(edges):
        adj[u].append((v, i+1))
        adj[v].append((u, i+1))
    def dfs(u, parent, order):
        for v, idx in adj[u]:
            if v != parent:
                if idx >= id[u]:
                    dp[v-1] = dp[u-1]
                    id[v] = idx
                else:
                    dp[v-1] = dp[u-1] + 1
                    id[v] = idx
                dfs(v, u, order)
    dfs(1, 0, 1)
    return max(dp)

# main program
t = int(input())
for _ in range(t):
    n = int(input())
    edges = [tuple(map(int, input().split())) for _ in range(n-1)]
    print(solve(n, edges))