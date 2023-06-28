class Solution:
    def numOfMinutes(
        self, n: int, headID: int, manager: List[int], informTime: List[int]
    ) -> int:
        adj = defaultdict(list)
        for i in range(len(manager)):
            adj[manager[i]].append(i)
        ans = 0

        def dfs(node):
            ret = 0
            for i in adj[node]:
                ret = max(ret, dfs(i))
            return ret + informTime[node]

        return dfs(adj[-1][0])
