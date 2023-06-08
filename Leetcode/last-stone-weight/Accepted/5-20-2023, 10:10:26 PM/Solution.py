// https://leetcode.com/problems/last-stone-weight

import heapq
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heapq.heapify(stones)
        last=0
        while len(stones)!=1:
            largest = heapq.nlargest(2, stones)
            stones.remove(largest[0])
            stones.remove(largest[1])
            if len(stones)==0:
                return largest[0]-largest[1]
            else:
                heapq.heappush(stones, largest[0]-largest[1])
        return stones[0]
