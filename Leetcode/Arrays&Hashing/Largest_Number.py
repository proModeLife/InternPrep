from typing import List

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        def compare(x, y):
            return int(str(y) + str(x)) - int(str(x) + str(y))
        
        nums.sort(key=functools.cmp_to_key(compare))
        result = ''.join(map(str, nums))
        # Remove any leading zeros
        result = result.lstrip('0')
        # If result is empty, return '0'
        return result if result else '0'