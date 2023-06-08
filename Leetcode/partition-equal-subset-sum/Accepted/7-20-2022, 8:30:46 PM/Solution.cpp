// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    // Time Complexity:- O(n*sum)
    // Space Complexity:- O(sum);
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2)
            return false;
        sum /= 2;
        vector<vector<bool>> dp(2,vector<bool>(sum+1));
        dp[0][0] = true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                dp[i%2][j] = dp[(i-1)%2][j];
                if(j>=nums[i-1])
                    dp[i%2][j] = dp[i%2][j] or dp[(i-1)%2][j-nums[i-1]];
            }
        }
        return dp[n%2][sum];
    }
};