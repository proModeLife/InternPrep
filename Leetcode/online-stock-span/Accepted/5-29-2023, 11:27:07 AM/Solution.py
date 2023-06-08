// https://leetcode.com/problems/online-stock-span

class StockSpanner:

    def __init__(self):
        self.stack=[]
        self.len=[]
        

    def next(self, price: int) -> int:
        if self.stack and price ==self.stack[-1]:
            self.stack.append(price)
            self.len.append(self.len[-1]+1)
            return self.len[-1]
        elif self.stack and price >self.stack[-1]:
            ret=self.len[-1]
            while ret<=len(self.stack) and price>=self.stack[-ret]:
                ret+=1
            self.len.append(ret)
            self.stack.append(price)
            return ret
        else:
            self.stack.append(price)
            self.len.append(1)
            return 1


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)