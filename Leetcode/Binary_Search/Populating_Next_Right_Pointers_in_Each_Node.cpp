/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;

        queue<pair<int, Node*>> q;
        q.push({0, root});

        while (!q.empty()) {
            int val;
            Node* curr;

            auto it = q.front();
            q.pop();

            val = it.first;
            curr = it.second;

            if (!q.empty() && q.front().first == val)
                curr->next = q.front().second;

            if (curr->left) {
                q.push({val + 1, curr->left});
                q.push({val + 1, curr->right});
            }
        }

        return root;
    }
};
