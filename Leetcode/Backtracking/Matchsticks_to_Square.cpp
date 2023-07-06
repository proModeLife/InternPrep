class Solution {
    bool dfs(vector<int> &sidesLength,const vector<int> &matches, int index, int target) 
    {
        if (index == matches.size())
            return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
        for (int i = 0; i < 4; ++i) 
        {
            if(sidesLength[i]+matches[index]>target)continue;
            sidesLength[i] += matches[index];
            if (dfs(sidesLength, matches, index + 1,target))
                return true;
            sidesLength[i] -= matches[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) 
    {
        if (nums.empty()) return false;
        long long sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum%4)return false;
        sort(nums.begin(),nums.end(),[](const int &l, const int &r){return l>r;});
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, nums, 0, (int)sum/4);
    }
};
