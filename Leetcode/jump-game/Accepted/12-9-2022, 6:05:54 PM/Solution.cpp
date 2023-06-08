// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            maxReach--;
            if(maxReach<0){return false;}
            maxReach= max(maxReach,nums[i]);
        }
        return true;
    }
};