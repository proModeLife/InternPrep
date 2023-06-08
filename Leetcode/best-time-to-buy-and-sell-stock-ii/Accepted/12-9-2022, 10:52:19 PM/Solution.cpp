// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:

  int maxProfit(vector<int>& prices) {
        int diff=0,total=0;
        for(int i=1;i<prices.size();i++)
        {
            diff=prices[i]-prices[i-1];
            if(diff>0)
            total+=diff;
        }
        return total;
    }
};