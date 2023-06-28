from collections import defaultdict, deque
from typing import List


class Solution:
    def shortestAlternatingPaths(
        self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]
    ) -> List[int]:
        adjR = defaultdict(list)
        adjB = defaultdict(list)
        for a, b in redEdges:
            adjR[a].append(b)
        for a, b in blueEdges:
            adjB[a].append(b)
        ansR = [float("inf")] * n
        ansB = [float("inf")] * n
        ansB[0] = 0
        ansR[0] = 0
        q = deque()
        for b in adjB[0]:
            q.append((1, b, "R"))
        for b in adjR[0]:
            q.append((1, b, "B"))
        while q:
            d, u, c = q.popleft()
            if c == "R":
                ansB[u] = min(ansB[u], d)
                for b in adjR[u]:
                    if ansR[b] > d + 1:
                        ansR[b] = d + 1
                        q.append((d + 1, b, "B"))
            else:
                ansR[u] = min(ansR[u], d)
                for b in adjB[u]:
                    if ansB[b] > d + 1:
                        ansB[b] = d + 1
                        q.append((d + 1, b, "R"))
        ans = []
        for i in range(n):
            val = min(ansR[i], ansB[i])
            ans.append(val) if val != float("inf") else ans.append(-1)
        return ans
