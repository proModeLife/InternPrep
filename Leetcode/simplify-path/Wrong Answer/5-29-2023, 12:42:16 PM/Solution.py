// https://leetcode.com/problems/simplify-path

class Solution:
    def simplifyPath(self, path: str) -> str:
        tmp = ""
        while tmp != path:
            tmp = path
            path = path.replace(".", "")
            path = path.replace("//", "/")
        if len(path) > 1 and path[-1] == '/':
            return path[:-1]
        else:
            return path
