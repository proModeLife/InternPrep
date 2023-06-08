// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
     vector<int> tmp;
     sort(nums.begin(),nums.end());
		dfs(nums,0,tmp,nums.size());
		return res;
	}
private:
	vector<vector<int>> res;
	void dfs(vector<int> nums,int cur,vector<int> tmp,int nums_size)
	{
		if(cur == nums_size)
		{
			res.push_back(tmp);
			return;
		}
		for(int i = 0; i< nums.size();i++)
		{   
            if(i>0 && nums[i]==nums[i-1])continue;
			//make
			int tmp_num = nums[i];
			tmp.push_back(tmp_num);
			nums.erase(nums.begin()+i);
			//backtracking
			dfs(nums,cur+1,tmp,nums_size);
			//unmake
			tmp.pop_back();
			nums.insert(nums.begin()+i,tmp_num);
		}
	}
};