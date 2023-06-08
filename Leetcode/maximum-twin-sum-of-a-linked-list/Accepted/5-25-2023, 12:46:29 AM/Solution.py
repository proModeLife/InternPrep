// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow,fast=head,head
        prev,next=None,slow.next
        while fast and fast.next:
            fast=fast.next.next
            tmp=slow
            slow=slow.next
            next=slow.next
            tmp.next=prev
            prev=tmp
        ans=slow.val+prev.val
        prev=prev.next
        while prev and next:
            ans=max(ans,prev.val+next.val)
            prev=prev.next
            next=next.next
        return ans



            
