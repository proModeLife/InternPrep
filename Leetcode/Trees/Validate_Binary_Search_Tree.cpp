
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, long long lval, long long rval) {
        if (root == nullptr)
            return true;
        
        if (root->val <= lval || root->val >= rval)
            return false;
        
        bool leftValid = helper(root->left, lval, root->val);
        bool rightValid = helper(root->right, root->val, rval);
        
        return leftValid && rightValid;
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
