class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        neighbours=defaultdict(list)
        indegree=[0]*numCourses
        for crs,pre in prerequisites:
            neighbours[pre].append(crs)
            indegree[crs]+=1
        queue=deque()
        for i in range(numCourses):
            if indegree[i]==0:
                queue.append(i)
        donecourses=0
        while queue:
            node=queue.popleft()
            donecourses+=1
            for neighbour in neighbours[node]:
                indegree[neighbour]-=1
                if indegree[neighbour]==0:
                    queue.append(neighbour)
        return donecourses==numCourses
