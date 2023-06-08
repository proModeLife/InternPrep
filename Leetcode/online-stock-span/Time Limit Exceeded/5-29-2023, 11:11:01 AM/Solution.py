// https://leetcode.com/problems/online-stock-span

class StockSpanner:

    def __init__(self):
        self.stack=[]
        

    def next(self, price: int) -> int:
        self.stack.append(price)
        ret=1
        while ret<=len(self.stack) and price>=self.stack[-ret]:
            ret+=1
        return ret-1


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)