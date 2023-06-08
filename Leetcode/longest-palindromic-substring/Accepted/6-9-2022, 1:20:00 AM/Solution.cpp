// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int l = 0;
        
        for(int i=0;i<s.length();i++)
        {
            int left = i;
            int right = i;
            while(left>=0 && right<s.length() && s[left]==s[right])
            {
               
                left--;
                right++;
            }
            right--; left++;
             if(right-left+1 > l)
                {
                    ans = s.substr(left,right-left+1);
                    l = right-left+1;
                }
            left = i;
            right = i+1;
            
            while(left>=0 && right<s.length() && s[left]==s[right])
            {
                
                left--;
                right++;
            }
            right--; left++;
            if(right-left+1 > l)
                {
                    ans = s.substr(left,right-left+1);
                    l = right-left+1;
                }
        }
        return ans;
    }
};