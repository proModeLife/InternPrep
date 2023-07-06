
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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int l1, int r1, int l2, int r2) {
        if (l1 > r1 || l2 > r2)
            return nullptr;

        int val = preorder[l1];
        TreeNode* root = new TreeNode(val);
        int len = 0;
        while (l2 + len <= r2 && inorder[l2 + len] != val) {
            len++;
        }
        root->left = helper(preorder, inorder, l1 + 1, l1 + len, l2, l2 + len - 1);
        root->right = helper(preorder, inorder, l1 + len + 1, r1, l2 + len + 1, r2);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
