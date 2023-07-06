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
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        TreeNode* curr =root;
        while(curr)
        {
            stk.push(curr);
            curr=curr->left;
        }
    }
    
    int next() {
        TreeNode* root = stk.top(); stk.pop();
        TreeNode* curr = root;
        while(curr && curr->right!=nullptr)
        {
            curr=curr->right;
            while(curr)
            {
                stk.push(curr);
                curr=curr->left;
            }
        }
        return root->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
