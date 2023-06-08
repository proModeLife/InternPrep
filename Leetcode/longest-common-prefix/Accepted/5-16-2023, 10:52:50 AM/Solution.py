// https://leetcode.com/problems/longest-common-prefix

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans=strs[0]
        for i in range(len(strs)):
            tmp=""
            for j in range(min(len(ans),len(strs[i]))):
                if(ans[j]==strs[i][j]):
                    tmp+=ans[j]
                else:
                    break
            if len(tmp) == 0 :
                return ""
            else: 
                ans=tmp
        return ans