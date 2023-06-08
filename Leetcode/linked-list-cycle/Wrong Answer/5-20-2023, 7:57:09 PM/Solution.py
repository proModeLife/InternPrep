// https://leetcode.com/problems/linked-list-cycle

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        curr=head
        if not curr or not curr.next:
            return False
        tmp=curr.next
        curr.next=None
        curr=tmp
        prev=head
        while curr :
            if curr.next and curr.next==head:
                return True
            tmp=curr.next
            curr.next=prev
            prev=curr
            curr=tmp
        return False
                