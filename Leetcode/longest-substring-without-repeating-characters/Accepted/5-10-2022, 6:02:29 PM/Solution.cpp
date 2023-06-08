// https://leetcode.com/problems/longest-substring-without-repeating-characters

#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length=0;
        for(int i=0; i<s.size();i++){
            map<char,int> m;
            int j=0,curr=0;
            while(i+j<s.size()){
                if(m.find(s[i+j])==m.end()){
                m[s[i+j]]=1;
                    j++;
                    curr++;
                }
                else{
                    max_length=max(max_length,curr);
                    m.clear();
                    break;
                }
            }
            max_length=max(max_length,curr);
        }
        return max_length;
    }
};