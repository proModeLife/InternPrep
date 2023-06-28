class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        p=points[0]
        heap=[]
        for i in range(1,len(points)):
            x=abs(points[i][0]-p[0])
            y=abs(points[i][1]-p[1])
            heap.append([x+y,points[i]])
        heapq.heapify(heap)
        cost=0
        while heap:
            c,pi=heapq.heappop(heap)
            cost+=c
            for i in range(len(heap)):
                x=abs(heap[i][1][0]-pi[0])
                y=abs(heap[i][1][1]-pi[1])
                heap[i][0]=min(heap[i][0],x+y)
            heapq.heapify(heap)
        return cost


