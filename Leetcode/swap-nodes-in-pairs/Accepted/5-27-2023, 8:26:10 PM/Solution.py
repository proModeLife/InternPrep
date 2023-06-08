// https://leetcode.com/problems/swap-nodes-in-pairs

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)  # Create a dummy node to simplify swapping
        dummy.next = head
        prev = dummy  # Pointer to the previous node before the pair
        while prev.next and prev.next.next:
            first = prev.next
            second = prev.next.next
            # Swapping the pair
            first.next = second.next
            second.next = first
            prev.next = second
            # Move prev and curr to the next pair
            prev = first
        return dummy.next
