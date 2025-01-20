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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* tmp = head->next;
        ListNode* p = head; 
        ListNode* x;
        p->next = nullptr;
        while(tmp!=nullptr){
            x = tmp->next;
            tmp->next = p;
            p = tmp;
            tmp = x;
        }
        return p;
    }
};