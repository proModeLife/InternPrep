// https://leetcode.com/problems/open-the-lock

from collections import deque

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        # Initialize the queue and the visited set
        queue = deque([('0000', 0)])
        visited = set(deadends)
        
        # Perform a BFS to find the shortest path to the target state
        while queue:
            curr, level = queue.popleft()
            
            if curr == target:
                return level
            
            if curr in visited:
                continue
            
            visited.add(curr)
            
            # Generate all possible next states by rotating one wheel in either direction
            for i in range(4):
                for d in [-1, 1]:
                    next_pos = curr[:i] + str((int(curr[i]) + d) % 10) + curr[i+1:]
                    if next_pos not in visited:
                        queue.append((next_pos, level+1))
        
        # If the target state is unreachable, return -1
        return -1