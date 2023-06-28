class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False] * (len(s) + 1)
        dp[0] = True
        for i in range(0, len(s)):
            for j in range(i, -1, -1):
                if dp[j] and (s[j:i + 1] in wordDict):
                    dp[i + 1] = True
                    break
        return dp[len(s)]
        