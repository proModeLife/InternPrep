// https://leetcode.com/problems/linked-list-cycle

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return False
        
        curr = head
        prev = None
        
        while curr:
            if curr.next and curr.next == head:
                return True
            
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
            
        return False