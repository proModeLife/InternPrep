# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return None
        
        # Find the length of the linked list
        ln = 0
        curr = head
        while curr:
            curr = curr.next
            ln += 1
        
        # Adjust k to avoid unnecessary rotations
        k %= ln
        if k == 0:
            return head
        
        # Find the new head and tail positions after rotation
        dl = ListNode()  # Dummy node for the new head
        dl.next = head
        slow = fast = dl
        
        # Move the fast pointer k steps ahead
        while k :
            fast = fast.next
            k -= 1
        
        # Move both pointers until the fast pointer reaches the end of the list
        while fast.next:
            slow = slow.next
            fast = fast.next
        
        # Perform the rotation
        new_head = slow.next
        slow.next = None
        fast.next = head
        
        return new_head
