// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0])return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long int>> dp (n,vector<long long int>(m,0));
        dp[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--){
            if(obstacleGrid[i][m-1])break;
            dp[i][m-1]=1;
        }
        for(int j=m-1;j>=0;j--){
            if(obstacleGrid[n-1][j])break;
            dp[n-1][j]=1;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(obstacleGrid[i][j])continue;
                long long int sum=0;
                if(!obstacleGrid[i+1][j])sum+=dp[i+1][j];
                if(!obstacleGrid[i][j+1])sum+=dp[i][j+1];
                dp[i][j]=sum;
            }
        }
        return dp[0][0];
    }
};