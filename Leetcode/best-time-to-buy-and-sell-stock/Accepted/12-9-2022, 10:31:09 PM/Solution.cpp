// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lo = prices[0],high=prices[0];
        int ans=0;
        for(auto it: prices){
            if(it<lo)lo=it;
            if(it>=lo){
                high=it;
                ans=max(ans,high-lo);
            }
            
        }
        return ans;
    }
};