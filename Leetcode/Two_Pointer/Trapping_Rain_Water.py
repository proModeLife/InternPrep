class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        right = [0] * n
        left = [0] * n
        rmax, lmax = height[n - 1], height[0]
        ans = 0
        for r in range(n - 1, -1, -1):
            if height[r] > rmax:
                rmax = height[r]
            else:
                right[r] = rmax
        for l in range(n):
            if height[l] > lmax:
                lmax = height[l]
            else:
                ans += max(min(lmax, right[l]) - height[l], 0)
        return ans
