// https://leetcode.com/problems/unique-binary-search-trees

class Solution {
public:
    long long int calc(int n, vector<long long int>&dp){
        if(dp[n]!=0)return dp[n];
        else{
            long long int sum=0;
            for(int i=0;i<n;i++){
                sum+=calc(i,dp)*calc(n-i-1,dp);
            }
            return dp[n]=sum;
        }
    }
    int numTrees(int n) {
        if(n==0) return 0;
        if(n==1)return 1;
        if(n==2)return 2;
        vector<long long int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        long long int res = calc(n,dp);
        return res;
    }
};