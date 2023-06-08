// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
    // sort the array
    std::sort(nums.begin(), nums.end());

    // initialize the closest sum to be the maximum possible value
    int closest_sum = INT_MAX;

    // loop through the array, starting at the first element
    for (int first = 0; first < nums.size(); first++) {
        // initialize the left and right pointers
        int left = first + 1;
        int right = nums.size() - 1;

        // loop until the left pointer is greater than the right pointer
        while (left < right) {
            // calculate the sum of the three numbers pointed to by the first, left, and right pointers
            int curr_sum = nums[first] + nums[left] + nums[right];

            // if the current sum is equal to the target, we have found the three numbers that have the closest sum to the target, so we can return the current sum
            if (curr_sum == target) {
                return curr_sum;
            }

            // if the current sum is less than the target, we need to increase the sum, so we move the left pointer to the next element
            if (curr_sum < target) {
                left++;
            }

            // if the current sum is greater than the target, we need to decrease the sum, so we move the right pointer to the previous element
            if (curr_sum > target) {
                right--;
            }

            // update the closest sum if the current sum is closer to the target than the previous closest sum
            if (std::abs(target - curr_sum) < std::abs(target - closest_sum)) {
                closest_sum = curr_sum;
            }
        }
    }

        
    

    // return the closest sum that we found
    return closest_sum;
}
};