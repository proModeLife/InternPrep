// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int find(int ind,vector<int>& prices,int count,bool buy, vector<vector<int>>& dp){
        if(ind==prices.size() || count==0)return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy){
            return dp[ind][buy]= max(-prices[ind]+find(ind+1,prices,count,!buy,dp),find(ind+1,prices,count,buy,dp));
        }
        else{
            return dp[ind][buy]= max(prices[ind]+find(ind+1,prices,count-1,!buy,dp),find(ind+1,prices,count,buy,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp (prices.size(),vector<int>(2,-1));
        int count = 2;
        return find(0,prices,count,true,dp);

    }
};