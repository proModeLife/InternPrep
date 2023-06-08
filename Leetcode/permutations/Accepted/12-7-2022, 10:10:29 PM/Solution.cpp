// https://leetcode.com/problems/permutations

class Solution {
public:
    void permute(vector<int>& a, int l, int r,vector<vector<int>>& result)
        {
            // Base case
            if (l == r)
                result.push_back(a);
            else {
                // Permutations made
                for (int i = l; i <= r; i++) {
        
                    // Swapping done
                    swap(a[l], a[i]);
        
                    // Recursion called
                    permute(a, l + 1, r,result);
        
                    // backtrack
                    swap(a[l], a[i]);
                }
            }
        }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permute(nums,0,nums.size()-1,result);
        return result;
    }
};