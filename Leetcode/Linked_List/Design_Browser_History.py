
#include <string>

using namespace std;

class BrowserHistory {
public:
    struct ListNode {
        ListNode* next;
        ListNode* prev;
        string val;
        
        ListNode(string val) {
            this->val = val;
            this->next = this->prev = nullptr;
        }
    };
    
    ListNode* start;
    ListNode* current;
    
    BrowserHistory(string homepage) {
        start = new ListNode(homepage);
        current = start;
    }
    
    void visit(string url) {
        ListNode* newNode = new ListNode(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    
    string back(int steps) {
        while (steps > 0 && current->prev != nullptr) {
            current = current->prev;
            steps--;
        }
        return current->val;
    }
    
    string forward(int steps) {
        while (steps > 0 && current->next != nullptr) {
            current = current->next;
            steps--;
        }
        return current->val;
    }
};
