from collections import deque


class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        colors = [-1] * len(graph)
        for i in range(len(graph)):
            if colors[i] != -1:
                continue

            q = deque([(i, 0)])
            while q:
                u, c = q.popleft()

                if colors[u] == -1:
                    colors[u] = c
                else:
                    if colors[u] != c:
                        return False
                    continue

                for v in graph[u]:
                    q.append((v, 1 - c))

        return True
