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
    long long curr=0;
    long long ans=0;
    void dfs(TreeNode* root)
    {
        curr=10*curr + root->val;
        if(!root->left && !root->right)ans+=curr;
        else
        {
            if(root->left)dfs(root->left);
            if(root->right)dfs(root->right);
        }
        curr/=10;
    }
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
