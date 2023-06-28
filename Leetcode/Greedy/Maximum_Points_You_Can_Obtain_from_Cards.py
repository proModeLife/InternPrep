class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        if k == len(cardPoints):
            return sum(cardPoints)
        ans = sum(cardPoints[:k])
        cur = ans
        for i in range(1, k + 1):
            cur = cur - cardPoints[k - i] + cardPoints[-i]
            ans = max(ans, cur)
        return ans
