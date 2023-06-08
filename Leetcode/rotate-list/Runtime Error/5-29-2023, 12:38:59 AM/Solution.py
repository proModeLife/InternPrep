// https://leetcode.com/problems/rotate-list

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
             return None
        ln=0
        curr=head
        while curr:
            curr=curr.next
            ln+=1
        k%=ln
        if k == 0 : return head
        dl= ListNode()
        curr=head
        while k:
            curr=curr.next
            k-=1
        dl.next=curr.next
        curr.next=None
        curr= dl.next
        while curr.next:
            curr=curr.next
        curr.next=head
        return dl.next