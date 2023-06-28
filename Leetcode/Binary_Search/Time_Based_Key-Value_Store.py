from collections import defaultdict
from bisect import bisect_right
from typing import List

class TimeMap:
    def __init__(self):
        self.map = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.map[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.map:
            return ""

        values = self.map[key]
        index = bisect_right(values, (timestamp, chr(127)))

        if index == 0:
            return ""

        return values[index - 1][1]
