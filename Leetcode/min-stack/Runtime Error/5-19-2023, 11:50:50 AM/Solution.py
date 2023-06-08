// https://leetcode.com/problems/min-stack

class MinStack:

    def __init__(self):
        self.count = {}
        self.s1 = []
        self.s2 = [float('inf')]

    def push(self, val: int) -> None:
        self.s1.append(val)
        if val <= self.s2[-1]:
            self.s2.append(val)
            self.count[val] = 1
        else:
            get = self.count.get(val, 0)
            self.count[val] = get + 1
        
    def pop(self) -> None:
        val = self.s1.pop()
        if val == self.s2[-1]:
            self.s2.pop()
            self.count[val] -= 1
            if self.count[val] == 0:
                del self.count[val]

    def top(self) -> int:
        return self.s1[-1]

    def getMin(self) -> int:
        return self.s2[-1]