// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced

class Solution:
    def minSwaps(self, s: str) -> int:
        left, right = 0, len(s) - 1
        while right > left and s[right] != '[':
            right -= 1
        count = 0
        ans = 0
        while left < right:
            if s[left] == '[':
                count -= 1
            else:
                count += 1
            if count == 1:
                ans += 1
                while right > left and s[right] != '[':
                    right -= 1
                count = -1
            left += 1
        return ans