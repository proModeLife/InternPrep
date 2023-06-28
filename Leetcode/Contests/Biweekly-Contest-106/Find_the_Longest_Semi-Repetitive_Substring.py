class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        n = len(s)
        if n <= 2:
            return n
        max_len = 2 
        pairs = [0] * n
        if s[0] == s[1]:
            pairs[1] = 1
        for i in range(2, n):
            if s[i] == s[i-1]:
                pairs[i] = pairs[i-1] + 1
            else:
                pairs[i]=pairs[i-1]
        i = 0
        j = 2
        while j < n:
            if pairs[j] - pairs[i] > 1:
                i += 1
            else:
                max_len = max(max_len, j-i+1)
            j += 1
        return max_len