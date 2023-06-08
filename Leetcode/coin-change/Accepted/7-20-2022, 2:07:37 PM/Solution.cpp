// https://leetcode.com/problems/coin-change

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,0));
        for(int t=0; t<=amount;t++){
            if(t % coins[0]==0) {dp[0][t]= t/coins[0];} 
            else{dp[0][t]= 1e9;}
        }
        for(int ind=1; ind<n;ind++){
            for(int t=0; t<=amount;t++){
                int notTake= dp[ind-1][t];
                int Take= INT_MAX;
                if(coins[ind]<=t){
                Take= 1+ dp[ind][t-coins[ind]];
                    }
                dp[ind][t]=min (notTake,Take);
            }
        }
        
        int ans=dp[n-1][amount];
        if(ans>=1e9) return -1;
        else return ans;
        
    }
};