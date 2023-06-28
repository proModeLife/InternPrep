
class SegmentTreeNode {
public:
    int l, r;
    int k, lazy;
    SegmentTreeNode* left;
    SegmentTreeNode* right;

    SegmentTreeNode(int l, int r, int k) {
        this->l = l;
        this->r = r;
        this->k = k;
        this->lazy = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void normalize(SegmentTreeNode* node) {
    if (node->l < node->r) {
        if (node->left == nullptr || node->right == nullptr) {
            int m = node->l + (node->r - node->l) / 2;
            node->left = new SegmentTreeNode(node->l, m, node->k);
            node->right = new SegmentTreeNode(m + 1, node->r, node->k);

        } else if (node->lazy > 0) {
            node->left->k += node->lazy;
            node->left->lazy += node->lazy;

            node->right->k += node->lazy;
            node->right->lazy += node->lazy;
        }
    }

    node->lazy = 0;
}

int query(SegmentTreeNode* node, int i, int j) {
    if (i > j || node == nullptr || i > node->r || j < node->l)
        return 0;

    if (i <= node->l && node->r <= j)
        return node->k;

    normalize(node);

    return std::max(query(node->left, i, j), query(node->right, i, j));
}

void update(SegmentTreeNode* node, int i, int j, int val) {
    if (i > j || node == nullptr || i > node->r || j < node->l)
        return;

    if (i <= node->l && node->r <= j) {
        node->k += val;
        node->lazy += val;
        return;
    }

    normalize(node);

    update(node->left, i, j, val);
    update(node->right, i, j, val);

    node->k = std::max(node->left->k, node->right->k);
}

class MyCalendarTwo {
public:
    SegmentTreeNode* root;

    MyCalendarTwo() {
        root = new SegmentTreeNode(0, 1'000'000'000, 0);
    }

    bool book(int start, int end) {
        int k = query(root, start, end - 1);
        if (k >= 2)
            return false;

        update(root, start, end - 1, 1);
        return true;
    }
};
