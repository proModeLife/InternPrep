// https://leetcode.com/problems/palindrome-partitioning

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        if len(s) <= 1:
            return [[s]]
        ans = []
        
        def dfs(ind, partition):
            if ind == len(s):
                ans.append(partition.copy())
                return
            for j in range(ind, len(s)):
                if s[ind:j+1] == s[ind:j+1][::-1]:
                    partition.append(s[ind:j+1])
                    dfs(j+1, partition)
                    partition.pop()
        
        partition = []
        dfs(0, partition)
        return ans