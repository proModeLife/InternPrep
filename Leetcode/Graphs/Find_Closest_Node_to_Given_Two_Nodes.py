from typing import List

class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        n = len(edges)
        distances1 = [float('inf')] * n
        distances2 = [float('inf')] * n
        
        # Initialize the queues for BFS
        queue1 = [node1]
        queue2 = [node2]
        
        # Initialize the distances from node1 and node2 to themselves
        distances1[node1] = 0
        distances2[node2] = 0
        
        # Perform BFS from node1 and node2
        while queue1 or queue2:
            if queue1:
                curr1 = queue1.pop(0)
                next_node1 = edges[curr1]
                if next_node1 != -1:
                    if distances1[next_node1] == float('inf'):
                        distances1[next_node1] = distances1[curr1] + 1
                        queue1.append(next_node1)
            if queue2:
                curr2 = queue2.pop(0)
                next_node2 = edges[curr2]
                if next_node2 != -1:
                    if distances2[next_node2] == float('inf'):
                        distances2[next_node2] = distances2[curr2] + 1
                        queue2.append(next_node2)
        
        # Find the node with minimum maximum distance
        min_max_distance = float('inf')
        min_node = -1
        for i in range(n):
            if distances1[i] != float('inf') and distances2[i] != float('inf'):
                max_distance = max(distances1[i], distances2[i])
                if max_distance < min_max_distance:
                    min_max_distance = max_distance
                    min_node = i
        
        return min_node
