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
    int curr=0;
    int ans;
    void dfs(TreeNode* root, int k)
    {
        if(curr>k)return;
        if(root->left)dfs(root->left,k);
        curr++;
        if(curr==k)ans=root->val;
        if(root->right)dfs(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }
};
