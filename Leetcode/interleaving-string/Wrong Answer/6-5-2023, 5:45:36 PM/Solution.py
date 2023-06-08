// https://leetcode.com/problems/interleaving-string

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:

        if len(s1) + len(s2) != len(s3):
            return False
        
        # Initialize the previous row of the dp array
        prev = [True] + [False] * len(s2)
        
        # Fill in the dp array row by row
        for i in range(1, len(s1) + 1):
            # Initialize the current row of the dp array
            curr = [False] * (len(s2) + 1)
            curr[0] = prev[0] and s1[i-1] == s3[i-1]
            
            for j in range(1, len(s2) + 1):
                curr[j] = (prev[j] and s1[i-1] == s3[i+j-1]) or (curr[j-1] and s2[j-1] == s3[i+j-1])
            
            # Update the previous row
            prev = curr
        
        return prev[-1]