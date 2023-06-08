// https://leetcode.com/problems/simplify-path

class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
    
        components = path.split('/')
        for component in components:
            # Ignore empty components and current directory '.'
            if component == '' or component == '.':
                continue
            
            # Handle parent directory '..' by popping from the stack
            if component == '..':
                if stack:
                    stack.pop()
            
            # Add valid directory names to the stack
            else:
                stack.append(component)
        
        # Construct the simplified canonical path using the directories in the stack
        simplified_path = '/' + '/'.join(stack)
        
        return simplified_path
