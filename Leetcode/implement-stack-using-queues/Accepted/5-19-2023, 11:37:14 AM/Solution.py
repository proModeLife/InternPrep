// https://leetcode.com/problems/implement-stack-using-queues

class MyStack:

    def __init__(self):
        self.curr = 0
        self.qus = [[], []]

    def push(self, x: int) -> None:
        self.qus[self.curr].append(x)

    def pop(self) -> int:
        while len(self.qus[self.curr]) > 1:
            self.qus[1 - self.curr].append(self.qus[self.curr].pop(0))
        self.curr = 1 - self.curr
        return self.qus[1 - self.curr].pop()

    def top(self) -> int:
        return self.qus[self.curr][-1]
        
    def empty(self) -> bool:
        return len(self.qus[self.curr]) == 0
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()