
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* start = dummy;
        ListNode* end1 = nullptr;
        ListNode* end2 = nullptr;
        
        for (int i = 0; i < k - 1; i++) 
        {
            start = start->next;
        }
        end2 = start->next;
        end1 = head;
        
        while (end2->next) {
            end1 = end1->next;
            end2 = end2->next;
        }
        
        swap(end1->val, start->next->val);
        
        return dummy->next;
    }
};
