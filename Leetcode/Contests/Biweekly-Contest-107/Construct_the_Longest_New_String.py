class Solution:
    def longestString(self, x: int, y: int, z: int) -> int:
        return min(x,y)*4+int(x!=y)*2+z*2
        