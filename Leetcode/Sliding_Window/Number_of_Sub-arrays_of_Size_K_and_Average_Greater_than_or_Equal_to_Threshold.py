class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        R = 0
        Sum = 0
        threshold *= k
        while R < k:
            Sum += arr[R]
            R += 1
        ans = 0
        ans += Sum >= threshold
        for L in range(len(arr) - k):
            Sum += arr[L + k] - arr[L]
            ans += Sum >= threshold
        return ans
