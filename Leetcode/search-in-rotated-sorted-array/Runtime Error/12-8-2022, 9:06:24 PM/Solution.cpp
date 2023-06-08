// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid;
        int find;
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] < nums[mid - 1]) {
                // Pivot index is the mid index
                start = mid;
                break;
            }
            if (nums[mid] > nums[start]) {
                // Pivot index is to the right of mid
                start = mid + 1;
            } else {
                // Pivot index is to the left of mid
                end = mid - 1;
            }
        }
        find =start;
        int ans =(find+target-nums[find])%nums.size();
        if(nums[ans]==target) return ans;
        return -1;
    }
};