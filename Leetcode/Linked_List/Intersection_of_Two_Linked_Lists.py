# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        lenA, lenB = 0, 0
        currA, currB = headA, headB
        
        # Find the lengths of the two linked lists
        while currA:
            currA = currA.next
            lenA += 1
        
        while currB:
            currB = currB.next
            lenB += 1
        
        # Reset the current pointers to the beginning of the linked lists
        currA, currB = headA, headB
        
        # Determine which linked list is longer and calculate the difference
        if lenA > lenB:
            for i in range(lenA - lenB):
                currA = currA.next
        else:
            for i in range(lenB - lenA):
                currB = currB.next
        
        # Traverse both linked lists until they intersect
        while currA and currB and currA != currB:
            currA = currA.next
            currB = currB.next
        
        # Return the intersection node or None if the linked lists do not intersect
        return currA