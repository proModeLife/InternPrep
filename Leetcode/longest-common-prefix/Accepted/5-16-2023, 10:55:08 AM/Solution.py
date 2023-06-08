// https://leetcode.com/problems/longest-common-prefix

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        minimum = len(strs[0])
        for i in range(1,len(strs)):
            if (len(strs[i]) < minimum):
                minimum = len(strs[i])

        result = ''
        for i in range(minimum):
            current = strs[0][i]

            for j in range(1,len(strs)):
                if (strs[j][i] != current):
                    return result

            result = result + current
        return result