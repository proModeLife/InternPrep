class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = [0] * 26
        for t in tasks:
            count[ord(t) - ord("A")] += 1
        count.sort()

        mval = count[-1] - 1
        idle = mval * n

        for i in range(len(count) - 2, -1, -1):
            idle -= min(mval, count[i])
        return idle + len(tasks) if idle > 0 else len(tasks)
