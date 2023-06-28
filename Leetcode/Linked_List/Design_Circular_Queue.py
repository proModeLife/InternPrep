class ListNode:
    def __init__(self, val=-1, next=None):
        self.val = val
        self.next = next


class MyCircularQueue:
    def __init__(self, k: int):
        self.head = ListNode()
        curr = self.head
        for i in range(k - 1):
            tmp = ListNode()
            curr.next = tmp
            curr = tmp
        curr.next = self.head
        self.tail = curr

    def enQueue(self, value: int) -> bool:
        if self.tail.next.val == -1:
            self.tail = self.tail.next
            self.tail.val = value
            return True
        return False

    def deQueue(self) -> bool:
        if self.head.val != -1:
            self.head.val = -1
            self.head = self.head.next
            return True
        return False

    def Front(self) -> int:
        return self.head.val

    def Rear(self) -> int:
        return self.tail.val

    def isEmpty(self) -> bool:
        return self.head.val == -1

    def isFull(self) -> bool:
        return self.tail.next.val != -1


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
