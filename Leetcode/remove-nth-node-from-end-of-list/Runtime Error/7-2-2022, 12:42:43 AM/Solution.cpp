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
        vector<ListNode*> vec;
        ListNode* curr=head;
        while(curr->next){
            vec.push_back(curr);
            curr= curr->next;
        }
        vec.push_back(curr);
        int N= vec.size();
        if(n==N){
            vec[0]= nullptr;
            return vec[1];
        }
        if(n==0){
            vec[N-2]->next=nullptr;
            return vec[0];
        }
        //vec[N-n]= nullptr;
        vec[N-n-1]->next=vec[N-n+1];
        return vec[0];
    }
};