// https://leetcode.com/problems/min-stack

class MinStack:
    def __init__(self):
        self.count = {}
        self.s1 = []
        self.s2 = [float('inf')]

    def push(self, val: int) -> None:
        self.s1.append(val)
        if val <= self.s2[-1]:
            if val not in self.count:
                self.count[val] = 1
            else:
                self.count[val] += 1
            self.s2.append(val)

    def pop(self) -> None:
        if self.s1:
            val = self.s1.pop()
            if val == self.s2[-1]:
                self.count[val] -= 1
                if self.count[val] == 0:
                    self.s2.pop()
            else:
                if val in self.count:
                    self.count[val] -= 1

    def top(self) -> int:
        if self.s1:
            return self.s1[-1]

    def getMin(self) -> int:
        if len(self.s2) > 1:
            return self.s2[-1]