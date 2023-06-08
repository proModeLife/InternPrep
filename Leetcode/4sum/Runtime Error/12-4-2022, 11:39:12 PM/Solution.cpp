// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
            std::sort(nums.begin(), nums.end());

    // initialize a set to store the unique quadruplets
    std::vector<std::vector<int>> quadruplets;

    // loop through the array, starting at the first element
    for (int a = 0; a < nums.size(); a++) {
        // loop through the array, starting at the second element
        for (int b = a + 1; b < nums.size(); b++) {
            // initialize the left and right pointers
            int left = b + 1;
            int right = nums.size() - 1;
             // loop until the left pointer is greater than the right pointer
            while (left < right) {
                // calculate the sum of the four numbers pointed to by the a, b, left, and right pointers
                int curr_sum = nums[a] + nums[b] + nums[left] + nums[right];

                // if the current sum is equal to the target, we have found a quadruplet, so we add it to the set of unique quadruplets
                if (curr_sum == target) {
                    quadruplets.push_back(std::vector<int>{nums[a], nums[b], nums[left], nums[right]});
                    left++;
                    right--;
                }

                // if the current sum is less than the target, we need to increase the sum, so we move the left pointer to the next element
                if (curr_sum < target) {
                    left++;
                }

                // if the current sum is greater than the target, we need to decrease the sum, so we move the right pointer to the previous element
                if (curr_sum > target) {
                    right--;
                }
            }
        }
    }
    auto end = std::unique(quadruplets.begin(), quadruplets.end());
    quadruplets.erase(end, quadruplets.end());
    vector<vector<int>> numbers= quadruplets;
    std::set<vector<int>> unique_numbers(numbers.begin(), numbers.end());

    // clear the vector
    numbers.clear();

    // insert the unique elements from the set back into the vector
    for (vector<int> num : unique_numbers) {
        numbers.push_back(num);
    }
    // convert the set of unique quadruplets to a vector and return it
    return numbers;
    }
};