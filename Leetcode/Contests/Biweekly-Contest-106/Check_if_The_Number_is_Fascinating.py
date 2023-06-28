class Solution:
    def isFascinating(self, n: int) -> bool:
        concatenated = str(n) + str(2*n) + str(3*n)
        digit_counts = Counter(concatenated)
        return all(digit_counts[str(i)] == 1 for i in range(1, 10)) and '0' not in digit_counts