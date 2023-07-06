
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> allPossibleFBT(int n) {
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        vector<TreeNode*> ans;
        if (n == 1) {
            ans.push_back(new TreeNode(0));
        } else {
            for (int i = 1; i < n; i += 2) {
                vector<TreeNode*> leftSubtrees = allPossibleFBT(i);
                vector<TreeNode*> rightSubtrees = allPossibleFBT(n - i - 1);
                for (TreeNode* left : leftSubtrees) {
                    for (TreeNode* right : rightSubtrees) {
                        TreeNode* root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        ans.push_back(root);
                    }
                }
            }
        }

        memo[n] = ans;
        return ans;
    }
};
