// https://leetcode.com/problems/copy-list-with-random-pointer

"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        
        # Create a dictionary to store the original nodes as keys and the copied nodes as values
        nodes = {}
        
        # Traverse the original linked list and create a new node for each node in the list
        # Store the original node as the key and the newly created node as the value in the dictionary
        curr = head
        while curr:
            nodes[curr] = Node(curr.val, None, None)
            curr = curr.next
        
        # Traverse the original linked list again and set the next and random pointers of the copied nodes
        curr = head
        while curr:
            nodes[curr].next = nodes.get(curr.next)
            nodes[curr].random = nodes.get(curr.random)
            curr = curr.next
        
        # Return the head of the copied linked list
        return nodes[head]