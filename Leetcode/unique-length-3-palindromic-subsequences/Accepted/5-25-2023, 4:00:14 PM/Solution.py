// https://leetcode.com/problems/unique-length-3-palindromic-subsequences

class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        res = set()
        left = set()
        right = collections.Counter(s)
        for i in range(len(s)):
            right[s[i]] -= 1
            for c in left:
                if c in right and right[c] > 0:
                    res.add((s[i], c))
            left.add(s[i])
        return len(res)