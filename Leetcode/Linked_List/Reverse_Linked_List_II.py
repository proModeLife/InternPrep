# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left==right:
            return head
        dummy=ListNode()
        dummy.next=head
        prevL=dummy
        curr=head
        ind=1
        while curr and ind!=left:
            prevL=curr
            curr=curr.next
            ind+=1
        prev=curr
        leftP=curr
        curr=curr.next
        ind+=1
        while curr and ind!=right:
            ind+=1
            tmp = curr.next
            curr.next=prev
            prev=curr
            curr=tmp
        prevL.next=curr
        tmp = curr.next
        curr.next=prev
        leftP.next=tmp
        return dummy.next

            
