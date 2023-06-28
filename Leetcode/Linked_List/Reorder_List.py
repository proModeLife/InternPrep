# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
        
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # Find the middle of the linked list
        slow, fast = head, head
        prev = None
        while fast and fast.next:
            fast = fast.next.next
            # prev = slow
            slow = slow.next
        
        # Reverse the second half of the linked list
        while slow:
            tmp = slow
            slow = slow.next
            tmp.next= prev
            prev = tmp
        
        # Merge the two halves of the linked list
        curr = head
        while curr and prev.next:
            next1, next2 = curr.next, prev.next
            curr.next = prev
            prev.next = next1
            curr = next1
            prev = next2