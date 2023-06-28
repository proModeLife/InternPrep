from collections import deque

class MyStack:

    def __init__(self):
        self.q = deque()

    def push(self, x: int) -> None:
        self.q1.append(x)

    def pop(self) -> int:
        while len(self.q1) > 1:
            self.q2.append(self.q1.popleft())
        element = self.q1.popleft()
        self.q1, self.q2 = self.q2, self.q1
        return element

    def top(self) -> int:
        while len(self.q1) > 1:
            self.q2.append(self.q1.popleft())
        element = self.q1.popleft()
        self.q2.append(element)
        self.q1, self.q2 = self.q2, self.q1
        return element

    def empty(self) -> bool:
        return not self.q1