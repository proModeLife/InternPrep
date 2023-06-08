// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=nums.size();
        for(int i =0;i<nums.size();i++){
            if(nums[i]==val){
                nums[i]=INT_MAX;
                ans--;
            }
        }
        sort(nums.begin(),nums.end());
        return ans;
    }
};