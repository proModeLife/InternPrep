class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        dp = [0] * (len(questions) + 1)
        for i in range(len(questions) - 1, -1, -1):
            val = questions[i][0]
            if i + questions[i][1] + 1 < len(questions):
                val += dp[1 + i + questions[i][1]]
            dp[i] = max(dp[i + 1], val)
        return dp[0]
