class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        n1 = defaultdict(list)
        n2 = defaultdict(list)

        for a, b in connections:
            n1[a].append(b)
            n2[b].append(a)

        s = [0]
        ans = 0
        visited = [False] * n
        visited[0] = True

        while s:
            v = s.pop()
            for x in n1[v]:
                if not visited[x]:
                    s.append(x)
                    visited[x] = True
                    ans += 1
            for x in n2[v]:
                if not visited[x]:
                    s.append(x)
                    visited[x] = True

        return ans