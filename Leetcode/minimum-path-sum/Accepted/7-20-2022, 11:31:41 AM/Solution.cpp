// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        // for(auto it: grid){
        //     n++;
        // }
        // for(auto it: grid[0]){
        //     m++;
        // }
        vector<int> dp(m, INT_MAX); 
        dp[0]=0;
        for(int i=0;i<n;i++){
            dp[0]+=grid[i][0];
            for(int j=1; j<m;j++){
                dp[j]=grid[i][j]+min(dp[j],dp[j-1]);
            }
        }
        return dp[m-1];
    }
};