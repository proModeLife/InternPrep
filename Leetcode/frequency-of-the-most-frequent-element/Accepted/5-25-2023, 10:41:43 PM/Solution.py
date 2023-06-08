// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        start = ops = curr = ans = 0
        c = Counter(nums)
        keys = sorted(c.keys())
        for x in range(len(keys)):
            if x > 0: ops += curr * (keys[x] - keys[x-1])
            while ops > k:
                ops -= (keys[x]-keys[start]) * c[keys[start]]
                curr -= c[keys[start]]
                start += 1
            curr += c[keys[x]]
            ans = max(ans, curr + ((k - ops) // (keys[x]-(keys[start-1])) if start > 0 else 0))
        return ans 