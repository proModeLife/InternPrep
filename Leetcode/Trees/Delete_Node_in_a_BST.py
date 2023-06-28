class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return None
        
        # Case 1: Deleting the root node
        if root.val == key:
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left
            else:
                # Find the successor (minimum value) in the right subtree
                successor = self.findMin(root.right)
                root.val = successor.val
                root.right = self.deleteNode(root.right, successor.val)
        
        # Case 2: Deleting a non-root node
        parent = None
        cur = root
        while cur:
            if key < cur.val:
                parent = cur
                cur = cur.left
            elif key > cur.val:
                parent = cur
                cur = cur.right
            else:
                if cur.left is None:
                    if cur == parent.left:
                        parent.left = cur.right
                    else:
                        parent.right = cur.right
                elif cur.right is None:
                    if cur == parent.left:
                        parent.left = cur.left
                    else:
                        parent.right = cur.left
                else:
                    successor = self.findMin(cur.right)
                    cur.val = successor.val
                    cur.right = self.deleteNode(cur.right, successor.val)
                break
        
        return root
    
    def findMin(self, node: TreeNode) -> TreeNode:
        while node.left:
            node = node.left
        return node
