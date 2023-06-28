class Solution {
public:
    void solve(int start, int end, const vector<int>& nums, vector<vector<long long>>& dp) {
        if (dp[start][end] != -1) return;
        if (end < start) {
            dp[start][end] = 0;
            return;
        }
        if (end - start == 0) {
            dp[start][end] = nums[start-1]*nums[start]*nums[start+1];
            return;
        }
        long long ans = 0;
        for (int i = start; i <= end; i++) {
            solve(start, i-1, nums, dp);
            solve(i+1, end, nums, dp);
            ans = max(ans, dp[start][i-1] + nums[i] * nums[start-1] * nums[end+1] + dp[i+1][end]);
        }
        dp[start][end] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<long long>> dp(n+2, vector<long long>(n+2, -1));
        solve(1, n, nums, dp);
        return dp[1][n];
    }
};
