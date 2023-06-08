// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating

class Solution:
    def minFlips(self, s: str) -> int:
        f = s
        tmp = ""
        count = 0  # Initialize counter
        while tmp != f:
            tmp = f
            f = f.replace("111", "101")
            f = f.replace("000", "010")
            f = f.replace("11", "01")
            f = f.replace("00", "10")
        count += sum(1 for a, b in zip(s, f) if a != b)  # Update counter

        return count
