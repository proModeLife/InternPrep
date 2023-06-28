from typing import List
from collections import defaultdict

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        if len(s) <= 10:
            return []
        store = defaultdict(int)
        for i in range(9, len(s)+1):
            store[s[i-10:i]] += 1
        ans = []
        for i in store:
            if store[i] > 1:
                ans.append(i)
        return ans

        # Add the following code to consider repeated sequences at the end of the string
        end_sequences = s[-10:]
        if store[end_sequences] > 1:
            ans.append(end_sequences)
        return ans
