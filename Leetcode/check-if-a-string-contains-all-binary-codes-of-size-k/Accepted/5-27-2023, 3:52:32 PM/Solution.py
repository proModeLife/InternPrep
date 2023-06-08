// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        if len(s) <= k:
            return False
        check = set()
        for i in range(len(s) - k + 1):
            check.add(s[i:i+k])
            if len(check) == 2 ** k:
                return True
        return False
