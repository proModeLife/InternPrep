class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        adj=defaultdict(list)
        for a,b in edges:
            adj[a].append(b)
            adj[b].append(a)
        def dfs(curr,par):
            time=0
            for child in adj[curr]:
                if child==par: continue
                childtime=dfs(child,curr)
                if hasApple[child] or childtime: time+=2+childtime
            return time
        return dfs(0,-1)
         
