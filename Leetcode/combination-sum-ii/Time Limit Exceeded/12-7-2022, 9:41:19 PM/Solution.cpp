// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int start,int target) {
    if(target==0){
        bool flag= false;
        for(auto it:res){
            if(it==curr)flag=true;
        }
        if(!flag)res.push_back(curr);
        return;
    }
    if (start == nums.size() || target<0) {
        return;
    }
    curr.push_back(nums[start]);
    backtrack(nums, res, curr, start+1,target-nums[start]);
    curr.pop_back();
    backtrack(nums, res, curr, start + 1,target);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,result,curr,0,target);
        return result;
    }
};