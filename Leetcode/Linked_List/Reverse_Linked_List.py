# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev_node=None
        next_node=head
        while next_node != None:
            node=next_node
            next_node=next_node.next
            node.next=prev_node
            prev_node=node
        head=prev_node
        return head