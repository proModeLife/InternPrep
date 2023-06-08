// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool f(int i, vector<int>& nums, int sum1, int sum2){
        if(i==nums.size()){
            return sum1==sum2;
        }
        return f(i+1,nums,sum1+nums[i],sum2) || f(i+1,nums,sum1,sum2+nums[i]);
    }
    bool canPartition(vector<int>& nums) {
        return f(0,nums,0,0);
    }
};