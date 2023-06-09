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
    long long flow=0;
    TreeNode* convertBST(TreeNode* root) {
        if(!root)return nullptr;
        convertBST(root->right);
        root->val+=flow;
        flow=root->val;
        convertBST(root->left);
        return root;
    }
};
