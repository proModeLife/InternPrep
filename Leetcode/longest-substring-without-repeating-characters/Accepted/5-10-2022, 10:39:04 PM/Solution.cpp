// https://leetcode.com/problems/longest-substring-without-repeating-characters

#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(256,0);
        int l=0,r=0,ans=0;
        while(r<s.size()){
                m[s[r]]++;
                while(m[s[r]]>1){
                    m[s[l]]--;
                    l++;
                }
            r++;
            ans = max(ans, r-l);
            }
        return ans;
        }
    };
