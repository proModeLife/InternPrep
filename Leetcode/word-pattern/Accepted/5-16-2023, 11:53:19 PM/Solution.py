// https://leetcode.com/problems/word-pattern

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s = s.split()
        map12, map21 = {}, {}
        if len(pattern) != len(s):
            return False
        for a, b in zip(pattern, s):
            if (a in map12 and map12[a] != b) or (b in map21 and map21[b] != a):
                return False
            map12[a] = b
            map21[b] = a
        return True