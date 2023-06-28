class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        adj = defaultdict(list)
        for a, b in roads:
            adj[a].append(b)
            adj[b].append(a)
        parent = [0] * (len(roads) + 1)
        ans = 0

        def dfs(u):
            nonlocal ans
            count = 1
            for v in adj[u]:
                if v != parent[u]:
                    parent[v] = u
                    count += dfs(v)
            ans += (count + seats - 1) // seats
            return count

        for v in adj[0]:
            dfs(v)
        return ans
