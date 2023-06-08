// https://leetcode.com/problems/time-based-key-value-store

from collections import defaultdict
from bisect import bisect_left
from typing import List

class TimeMap:
    def __init__(self):
        self.map = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.map[key].append([timestamp, value])

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.map:
            return ""

        values = self.map[key]
        left = 0
        right = len(values) - 1

        while left <= right:
            mid = (left + right) // 2
            if values[mid][0] <= timestamp:
                if mid == len(values) - 1 or values[mid + 1][0] > timestamp:
                    return values[mid][1]
                else:
                    left = mid + 1
            else:
                right = mid - 1

        return ""
