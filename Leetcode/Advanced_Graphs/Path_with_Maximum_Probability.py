import heapq
from math import log
from typing import List

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        # Build adjacency list
        adj = [[] for _ in range(n)]
        for i in range(len(edges)):
            u, v = edges[i]
            adj[u].append((v, -log(succProb[i])))
            adj[v].append((u, -log(succProb[i])))
        
        # Initialize variables
        pq = [(0, start)]
        dist = [float('inf')] * n
        dist[start] = 0
        visited = set()
        
        # Run Dijkstra's algorithm
        while pq:
            d, u = heapq.heappop(pq)
            if u == end:
                return 1/pow(e, d)
            if u in visited:
                continue
            visited.add(u)
            for v, w in adj[u]:
                if d + w < dist[v]:
                    dist[v] = d + w
                    heapq.heappush(pq, (dist[v], v))
        
        return 0.0