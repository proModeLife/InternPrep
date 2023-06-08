// https://leetcode.com/problems/merge-two-sorted-lists

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head, res=None, None
        if list1 and list2:
            if list1.val < list2.val:
                res=list1
                list1=list1.next
            else: 
                res=list2
                list2=list2.next
        elif list1:
            return list1
        elif list2:
            return list2
        else:
            return None
        head=res
        while list1 and list2:
            if list1.val < list2.val:
                res.next=list1
                res=res.next
                list1=list1.next
            else:
                res.next=list2
                res=res.next
                list2=list2.next
        if list1:
            res.next=list1
        elif list2:
            res.next=list2
        return head

