class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegree=[0]*numCourses
        neighbours=defaultdict(list)
        for crs,pre in prerequisites:
            neighbours[pre].append(crs)
            indegree[crs]+=1
        queue=deque()
        for i in range(numCourses):
            if indegree[i]==0:
                queue.append(i)
        ans=[]
        while queue:
            node=queue.popleft()
            ans.append(node)

            for neighbour in neighbours[node]:
                indegree[neighbour]-=1
                if indegree[neighbour]==0:
                    queue.append(neighbour)
        return ans if len(ans)==numCourses else []