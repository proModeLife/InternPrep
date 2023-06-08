// https://leetcode.com/problems/longest-palindromic-substring

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string helper(string s, int i){
        int l=i-1, r=i+1;
        string ans1= "",ans2="";
        ans1+= s[i];
        //ans2+=s[i];
        while(l>0 && r<s.size()&& s[l]==s[r]){
            ans1 = s[l]+ans1+s[r];
            //cout<<"s[l]: "<<s[l]<<" s[r]: "<<s[r]<<endl;
            l--;
            r++;
        }
        r=i+1;
        while(i>0 && r<s.size()&& s[i]==s[r]){
            ans2 = s[i]+ans2+s[r];
            i--;
            r++;
        }
        if(ans1.size()>ans2.size()){
        return ans1;}
        return ans2;

    }
    string longestPalindrome(string s) {
        int maxlen=0;
        string ans= "";
        for(int i=0; i<s.size();i++){
            string temp= helper(s,i);
            int len = temp.size();
            if(len>maxlen){
                maxlen=len;
                ans = temp;
            }
        }
        return ans;
    }
};