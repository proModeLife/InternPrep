from typing import List

def query(index: int, left_limit: int, right_limit: int, left: int, right: int, st: List[int]) -> int:
    if left <= left_limit and right_limit <= right:
        return st[index]
    elif right_limit < left or right < left_limit:
        return 0
    mid = (left_limit + right_limit) // 2
    return query(2 * index, left_limit, mid, left, right, st) + query(2 * index + 1, mid + 1, right_limit, left, right, st)

def is_power_of_two(n: int) -> bool:
    return n != 0 and (n & (n - 1)) == 0
class NumArray:
    def __init__(self, nums: List[int]):
        n=len(nums)
        while not is_power_of_two(n):
            nums.append(0)
            n+=1
        self.n = len(nums)
        self.st = [0] * (2 * self.n)
        for i in range(self.n):
            self.st[self.n + i] = nums[i]
        for i in range(self.n - 1, 0, -1):
            self.st[i] = self.st[2 * i] + self.st[2 * i + 1]

    def update(self, index: int, val: int) -> None:
        self.st[index + self.n] = val
        j = (index + self.n)//2
        while j >= 1:
            self.st[j] = self.st[2 * j] + self.st[2 * j ^ 1]
            j //= 2

    def sumRange(self, left: int, right: int) -> int:
        return query(1, 0, self.n - 1, left, right, self.st)
