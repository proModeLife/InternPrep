class Solution
{
    public:

        long long solve(vector<int>& nums, int i,int chance,vector<vector<long long int>>&dp)
        {
            if(i==nums.size())return 0;
            if(dp[i][chance]!=-1)return dp[i][chance];
            if (chance)
            {
                long long use= nums[i]+solve(nums,i+1,0,dp);
                long long skip= solve(nums,i+1,1,dp);
                return dp[i][1]=max(use,skip);
            }
            else
            {
                long long use= -nums[i]+solve(nums,i+1,1,dp);
                long long skip= solve(nums,i+1,0,dp);
                return dp[i][0]=max(use,skip);
            }
        }
        long long maxAlternatingSum(vector<int>& nums)
        {
            int n = nums.size();
            vector<vector<long long int>> dp(n,vector<long long int>(2,-1));
            return solve(nums,0,1,dp);
        }
};
