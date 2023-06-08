// https://leetcode.com/problems/happy-number

class Solution:
    def isHappy(self, n: int) -> bool:
        visited=set()
        while True:
            visited.add(n)
            digit_sum = 0
            for digit in str(n):
                digit_sum += int(digit)*int(digit)
            if digit_sum == 1:
                return True
            elif digit_sum in visited:
                return False
            else:
                n=digit_sum
