class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        ratios = defaultdict(int)
        for a, b in rectangles:
            ratios[a / b] += 1
        ans = 0
        for key in ratios:
            ans += (ratios[key] * (ratios[key] - 1)) // 2
        return ans