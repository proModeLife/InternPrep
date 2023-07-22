class Solution {
public:
    bool used[1<<16 + 2];
    int target;

    bool backtrack(std::vector<int>& nums, int idx, int currSum, int left) {
        if (left == 0) 
        {
            return true;
        }
        if (currSum == target) 
        {
            return backtrack(nums, 0, 0,left-1);
        }
        for (int i = idx; i < nums.size(); i++) {
            if (used[i] || nums[i] + currSum > target) {
                continue;
            }
            used[i] = true;
            if (backtrack(nums, i + 1, currSum + nums[i],left)) {
                return true;
            }
            used[i] = false;
            if(!currSum || currSum+nums[i]==target)return false; // ultra optimizing line !!!
        }
        return false;
    }

    bool canPartitionKSubsets(std::vector<int>& nums, int k) {
        target = 0;
        for (int num : nums) {
            target += num;
        }
        if (target % k != 0 || k > nums.size()) {
            return false;
        }
        target /= k;
        std::memset(used, false, sizeof(used));
        std::sort(nums.begin(), nums.end(), [](const int& a, const int& b) { return a > b; });
        if (nums[0] > target) {
            return false;
        }
        return backtrack(nums, 0, 0, k);
    }
};
