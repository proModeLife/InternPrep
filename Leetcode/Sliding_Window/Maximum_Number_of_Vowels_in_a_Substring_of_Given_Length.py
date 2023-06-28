class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        r = 0
        curr, ans = 0, 0
        vowels = ["a", "e", "i", "o", "u"]
        while r < len(s) and r < k:
            curr += s[r] in vowels
            r += 1
        ans = curr
        while r < len(s):
            curr = curr + (s[r] in vowels) - (s[r - k] in vowels)
            ans = max(ans, curr)
            if ans == k:
                return k
            r += 1
        return ans
