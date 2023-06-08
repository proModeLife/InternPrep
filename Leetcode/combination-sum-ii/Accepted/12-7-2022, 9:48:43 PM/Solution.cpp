// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
//     void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int start,int target) {
//     if(target==0){
//         bool flag= false;
//         for(auto it:res){
//             if(it==curr)flag=true;
//         }
//         if(!flag)
//         res.push_back(curr);
//         return;
//     }
//     if (start == nums.size() || target<0) {
//         return;
//     }
//     curr.push_back(nums[start]);
//     backtrack(nums, res, curr, start+1,target-nums[start]);
//     curr.pop_back();
//     backtrack(nums, res, curr, start + 1,target);
// }
    void combinations(int ind,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<arr.size();i++)
        {
            if(i>ind&& arr[i]==arr[i-1]) continue;
            if(arr[i]>target)break;
            ds.push_back(arr[i]);
            combinations(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        // backtrack(candidates,result,curr,0,target);
        combinations(0,target,candidates,result,curr);
        return result;
    }
};