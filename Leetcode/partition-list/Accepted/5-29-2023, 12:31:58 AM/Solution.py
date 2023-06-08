// https://leetcode.com/problems/partition-list

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        dl1, dl2 = ListNode(), ListNode()  # dummy lists for smaller and greater than or equal values
        cur1, cur2 = dl1, dl2
        curr = head
        while curr:
            if curr.val < x:
                cur1.next = curr
                cur1 = cur1.next
            else:
                cur2.next = curr
                cur2 = cur2.next
            curr = curr.next
        
        cur2.next = None  # Set the next of the last node in cur2 to None
        cur1.next = dl2.next  # Append the list of greater than or equal values to the end of cur1
        
        return dl1.next
