// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(auto it: nums) total+= it;
        if(total %2==1 || nums.size()==1) return false;
        total/=2;
        vector<bool> prev(total+1,0),curr(total+1,0);
        prev[0]=curr[0]=true;
        prev[nums[0]]=true;
        for(int i=1; i<nums.size();i++){
            for(int t=1;t<=total;t++){
                bool notTake= prev[t];
                bool Take = false;
                if(nums[i]<= t){
                Take= prev[t-nums[i]];
                 }
                curr[t]=Take | notTake;
            }
            prev= curr;
        }
        return prev[total];
    }
};