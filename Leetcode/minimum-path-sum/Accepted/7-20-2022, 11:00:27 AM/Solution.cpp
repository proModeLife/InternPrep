// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int f(int i,int j,int n,int m,vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(i==n &&j==m){
            return grid[i][j];
        }
        if(i>n || j>m){
            return 101*101;
        }
        if(dp[i][j]!=-1) return dp[i][j];   
        else{
         
        return dp[i][j]=grid[i][j] + std::min(f(i+1,j,n,m,grid,dp),f(i,j+1,n,m,grid,dp));}
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=0,m=0;
        for(auto it: grid){
            n++;
        }
        for(auto it: grid[0]){
            m++;
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,n-1,m-1,grid,dp);
    }
};