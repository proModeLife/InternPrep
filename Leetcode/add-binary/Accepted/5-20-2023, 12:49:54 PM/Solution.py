// https://leetcode.com/problems/add-binary

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(a) < len(b):
            a = "0" * (len(b) - len(a)) + a
        else:
            b = "0" * (len(a) - len(b)) + b
        i = len(a) - 1
        c = ""
        carry = 0
        while i >= 0:
            bit_sum = int(a[i]) + int(b[i]) + carry
            c = str(bit_sum % 2) + c
            carry = bit_sum // 2
            i -= 1
        if carry == 1:
            c = "1" + c
        return c