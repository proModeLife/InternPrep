// https://leetcode.com/problems/add-two-numbers

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy=ListNode()
        res=dummy
        c1,c2=l1,l2
        carry=0
        while c1 and c2:
            val = c1.val+c2.val+carry
            carry=0
            if val>9:
                val-=10
                carry=1
            res.next=ListNode(val)
            res=res.next
            c1=c1.next
            c2=c2.next
        while c1 : 
            val = c1.val+carry
            carry=0
            if val>9:
                val-=10
                carry=1
            res.next=ListNode(val)
            res=res.next
            c1=c1.next
        while c2 : 
            val = c2.val+carry
            carry=0
            if val>9:
                val-=10
                carry=1
            res.next=ListNode(val)
            res=res.next
            c2=c2.next
        if carry==1:
            res.next=ListNode(1)
        return dummy.next
        