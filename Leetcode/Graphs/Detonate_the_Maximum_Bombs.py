from typing import List
from collections import defaultdict


class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        # Create adjacency list representation of the bombs graph
        n = len(bombs)
        adj = defaultdict(list)
        for i in range(n):
            for j in range(i + 1, n):
                dist = (
                    (bombs[i][0] - bombs[j][0]) ** 2 + (bombs[i][1] - bombs[j][1]) ** 2
                ) ** 0.5
                if dist <= bombs[i][2]:
                    adj[i].append(j)
                if dist <= bombs[j][2]:
                    adj[j].append(i)

        # Traverse the graph using DFS and compute the maximum number of detonations
        def dfs(u, visit):
            if u in visit:
                return 0
            visit.add(u)
            curr = 1
            for v in adj[u]:
                curr += dfs(v, visit)
            return curr

        ans = 0
        for i in range(n):
            ans = max(dfs(i, set()), ans)
        return ans
