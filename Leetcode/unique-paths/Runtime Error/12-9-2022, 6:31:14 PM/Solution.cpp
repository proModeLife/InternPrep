// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n+1, vector<int> (m+1,0));
        dp[n][m]=1;
        for(int j=m;j>=0;j--){
                dp[n][j]= 1;
            }
        for(int i=n;i>=0;i--){
                dp[i][m]= 1;
            }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j]= dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[1][1];
    }
};