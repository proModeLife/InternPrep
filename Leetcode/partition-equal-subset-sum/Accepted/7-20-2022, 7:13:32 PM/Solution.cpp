// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool f(int i, vector<int>& nums, int target,vector<vector<int>> &dp ){
        if(target==0) return true;
        if(i==0 ){
            return target==nums[0];
        }
        if(dp[i][target]!= -1) return dp[i][target]==1;
        bool notTake = f(i-1,nums,target,dp);
        bool Take = false;
        if(nums[i]<= target){
        Take= f(i-1,nums,target-nums[i],dp);
        }

        return dp[i][target]=Take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(auto it: nums) total+= it;
        if(total %2==1) return false;
        total/=2;
        vector<vector<int>> dp (nums.size()+1,vector<int>(total+1,-1));
        return f(nums.size()-1,nums,total,dp);
    }
};