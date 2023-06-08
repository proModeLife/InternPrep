// https://leetcode.com/problems/find-eventual-safe-states

from collections import defaultdict, deque
from typing import List

class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        back = defaultdict(list)
        q = deque()
        safe = [False] * len(graph)
        count = [0] * len(graph)
        
        for i in range(len(graph)):
            count[i] = len(graph[i])
            if len(graph[i]) == 0:
                safe[i] = True
                q.append(i)
            for j in graph[i]:
                back[j].append(i)
        
        while q:
            d = q.pop()
            for i in back[d]:
                count[i] -= 1
                if count[i] == 0 and not safe[i]:
                    safe[i] = True
                    q.append(i)
        
        ans = []
        for i in range(len(safe)):
            if safe[i]:
                ans.append(i)
        
        return ans
