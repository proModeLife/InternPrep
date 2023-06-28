class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        curr, reach = 0, 0
        ans = 0
        for i in range(n - 1):
            reach = max(reach, i + nums[i])
            if i == curr:
                curr = reach
                ans += 1

        return ans
