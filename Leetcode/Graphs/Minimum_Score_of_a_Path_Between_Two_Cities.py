class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        adj = defaultdict(list)
        for a, b, c in roads:
            a -= 1
            b -= 1
            adj[a].append((b, c))
            adj[b].append((a, c))
        visited = [False] * n
        ans = float("inf")

        def dfs(u):
            nonlocal ans
            visited[u] = True
            for v, c in adj[u]:
                ans = min(ans, c)
                if not visited[v]:
                    dfs(v)

        dfs(0)
        return ans
