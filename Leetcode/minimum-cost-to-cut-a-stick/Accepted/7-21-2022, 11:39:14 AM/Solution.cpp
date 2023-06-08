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
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),-1) );
        return f(1,cuts.size()-2,cuts,dp);
    }
};