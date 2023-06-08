// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int f(int i, int j, vector<int> arr,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int k=i;k<=j;k++){
            ans=max(ans, f(i,k-1,arr,dp)+f(k+1,j,arr,dp)+arr[i-1]*arr[k]*arr[j+1]);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        vector<vector< int>> dp (N+2,vector<int>(N+2,0));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        // return f(1,N,nums,dp);
        for(int i=N; i>=1;i--){
            for(int j=1; j<=N;j++){
                if(i>j) continue;
                int ans=0;
                for(int k=i;k<=j;k++){
                    ans=max(ans, dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]);
                }
                dp[i][j]=ans;
                
            }
        }
        return dp[1][N];
    }
};