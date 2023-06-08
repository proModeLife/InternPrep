// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    int rec(vector<string>& strs,vector<vector<int>> &dp,int k, int m, int n){
        if(k <0) return 0;
        if(m<0 || n<0) return -1e9;
        if(dp[m][n]!=-1)return dp[m][n];
        int a=0,b=0;
        for(auto i:strs[k] ){
            if(i=='0') a++;
            else b++;
        }
        return dp[m][n]= max(rec(strs,dp,k-1,m,n),1+ rec(strs,dp,k-1,m-a,n-b));
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size()-1;
        vector<vector<int>> dp (m+1, vector<int> (n+1,-1));
        return rec(strs,dp,len,m,n);
    }
};