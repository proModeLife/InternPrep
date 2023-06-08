// https://leetcode.com/problems/add-two-numbers

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        res = dummy
        carry = 0
        
        while l1 or l2 or carry:
            val = carry
            
            if l1:
                val += l1.val
                l1 = l1.next
                
            if l2:
                val += l2.val
                l2 = l2.next
                
            carry = val // 10
            val %= 10
            
            res.next = ListNode(val)
            res = res.next
        
        return dummy.next