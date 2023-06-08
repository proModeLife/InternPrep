// https://leetcode.com/problems/course-schedule-iv

class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        adj=defaultdict(list)
        preMap=defaultdict(set)
        for pre,crs in prerequisites:
            adj[crs].append(pre)
        
        def dfs(crs):
            if not crs in preMap:
                for pre in adj[crs]:
                    preMap[crs]|=dfs(pre)
                preMap[crs].add(crs)
            return preMap[crs]

        for crs in range(numCourses):
            dfs(crs)
        res=[]
        for pre, crs in queries:
            res.append(pre in preMap[crs])
        return res