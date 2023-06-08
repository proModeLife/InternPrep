// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating

class Solution:
    def minFlips(self, s: str) -> int:
        alt1, alt2 = "", ""
        diff1, diff2 = 0, 0
        n = len(s) 
        s = s + s
        ans = len(s)

        for i in range(len(s)):
            alt1 += '0' if i % 2 else '1'
            alt2 += '1' if i % 2 else '0'
            if i<n:
                diff1 += (s[i] != alt1[i])
                diff2 += (s[i] != alt2[i])

        l, r = 0, n-1
        ans = min(ans, diff1, diff2)

        while r + 1 < len(s):
            r += 1
            diff1 += (s[r] != alt1[r])
            diff2 += (s[r] != alt2[r])
            diff1 -= (s[l] != alt1[l])
            diff2 -= (s[l] != alt2[l])
            l += 1
            ans = min(ans, diff1, diff2)

        return ans
