// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(string str: strs){
            int i=0;
            while(i<min(str.length(),ans.length()) && str[i]==ans[i]){
                i++;
            }
            ans=ans.substr(0,i);
        }
        return ans;
    }
};