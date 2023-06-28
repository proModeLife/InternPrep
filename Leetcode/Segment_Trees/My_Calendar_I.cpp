
class Node {
public:
    int start, end;
    Node* left;
    Node* right;
    Node(int start, int end) {
        this->start = start;
        this->end = end;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class SGT {
public:
    Node* root;
    SGT() {
        root = nullptr;
    }
    
    void add(int start, int end) 
    {
        root = add(start, end, root);
    }
    
    Node* add(int start, int end, Node* root) {
        if (start > end)
            return nullptr;
        if (!root)
            return new Node(start, end);
        if (end < root->start)
            root->left = add(start, end, root->left);
        else if (start > root->end)
            root->right = add(start, end, root->right);
        return root;
    }
    
    bool find(int start, int end) {
        return find(start, end, root);
    }
    
    bool find(int start, int end, Node* root) {
        if (!root)
            return false;
        if (root->start == start && root->end == end)
            return true;
        if (end < root->start)
            return find(start, end, root->left);
        else if (start > root->end)
            return find(start, end, root->right);
        else
            return true;
    }
};

class MyCalendar {
public:
    SGT st;
    MyCalendar() {
    }
    
    bool book(int start, int end) 
    {
        end--;
        if (st.find(start, end))
            return false;
        st.add(start, end);
        return true;
    }
};
