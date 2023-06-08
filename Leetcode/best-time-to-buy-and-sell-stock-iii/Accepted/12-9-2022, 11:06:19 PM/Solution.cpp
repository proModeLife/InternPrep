// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int maxProfit(vector<int>& prices) {
        int sold[2] = {}, bought[2] = {INT_MIN, INT_MIN};
        for (int x : prices) {
            bought[0] = max(bought[0], -x);
            sold[0] = max(sold[0], bought[0] + x);
            bought[1] = max(bought[1], sold[0] - x);
            sold[1] = max(sold[1], bought[1] + x);
        }
        return max(sold[0], sold[1]);
    }
};