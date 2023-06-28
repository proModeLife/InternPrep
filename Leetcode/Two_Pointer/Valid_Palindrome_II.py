class Solution:
    def validPalindrome(self, s: str) -> bool:
        if len(s) <= 2:
            return True
        i, j = 0, len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return self.isPalindrome(s[i+1:j+1]) or self.isPalindrome(s[i:j])
            i += 1
            j -= 1
        return True

    def isPalindrome(self, s: str) -> bool:
        return s == s[::-1]