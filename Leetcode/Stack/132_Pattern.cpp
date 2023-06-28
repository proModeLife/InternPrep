class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        vector<int> mins(nums.size());
        mins[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            mins[i] = min(nums[i], mins[i-1]);
        }
        
        for (int j = nums.size() - 1; j >= 0; j--) {
            if (nums[j] > mins[j]) {
                while (!stk.empty() && stk.top() <= mins[j]) {
                    stk.pop();
                }
                
                if (!stk.empty() && nums[j] > stk.top()) {
                    return true;
                }
                
                stk.push(nums[j]);
            }
        }
        
        return false;
    }
};
