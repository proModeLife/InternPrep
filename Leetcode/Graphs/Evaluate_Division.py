from collections import defaultdict, deque
from typing import List


class Solution:
    def calcEquation(
        self, equations: List[List[str]], values: List[float], queries: List[List[str]]
    ) -> List[float]:
        adj = defaultdict(list)
        for i in range(len(equations)):
            a, b = equations[i]
            adj[a].append((b, values[i]))
            adj[b].append((a, 1 / values[i]))

        ans = []
        for a, b in queries:
            if a not in adj or b not in adj:
                ans.append(-1.0)
                continue

            visited = set()
            q = deque([(a, 1.0)])
            found = False

            while q and not found:
                src, val = q.popleft()

                if src == b:
                    ans.append(val)
                    found = True
                    break

                visited.add(src)

                for node, weight in adj[src]:
                    if node not in visited:
                        q.append((node, val * weight))

            if not found:
                ans.append(-1.0)

        return ans
