// https://leetcode.com/problems/minimum-cost-to-cut-a-stick

class Solution {
public:
    int f(int i, int j, vector<int>& cuts,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        else{
        int mini = 1e9;
        for(int k=i;k<=j;k++){
            mini= min(mini, cuts[j+1]-cuts[i-1]+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp));
        }
        
        return dp[i][j]=mini;
        }
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,0));
        for(int i=cuts.size()-2;i>=1;i--){
            for(int j=i;j<=cuts.size()-2;j++){
                int mini=1e9;
                for(int k=i;k<=j;k++){
                mini= min(mini, cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j]);
                             }
                dp[i][j]=mini;
            }
        }
        return dp[1][cuts.size()-2];
    }
};