// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* home= new ListNode(-1);
        home->next= head;
        ListNode* listNode1= home;
        while(n--){
            listNode1=listNode1->next;
        }
        ListNode* listNode2= home;
        while(listNode1->next){
            listNode1=listNode1->next;
            listNode2=listNode2->next;
        }
        listNode2->next= listNode2->next->next;
        return head;}
};