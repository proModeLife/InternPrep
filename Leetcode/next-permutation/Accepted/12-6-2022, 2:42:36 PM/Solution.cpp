// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums)
{
    int len = nums.size();

    // Find the first element from the right that is smaller than the element
    // immediately after it
    int idx = len - 2;
    while (idx >= 0 && nums[idx] >= nums[idx + 1])
    {
        idx--;
    }

    // If no such element is found, the array is already in non-ascending order
    // and the next permutation is the array sorted in ascending order
    if (idx < 0)
    {
        sort(nums.begin(), nums.end());
        return;
    }

    // Find the smallest element in the suffix that is greater than nums[idx]
    int jdx = len - 1;
    while (nums[jdx] <= nums[idx])
    {
        jdx--;
    }

    // Swap the elements at indices idx and jdx
    swap(nums[idx], nums[jdx]);

    // Reverse the suffix
    reverse(nums.begin() + idx + 1, nums.end());
}

};