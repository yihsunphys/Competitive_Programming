// 可以用快慢指針做
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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* p = head;
        while(p!=nullptr){
            n++;
            p = p->next;
        }
        if(n==1) return nullptr;
        p = head;
        n/=2;n--;
        while(n--){
            p = p->next;
        }
        ListNode* tmp = p->next;
        p->next = tmp->next;
        delete(tmp);
        return head;
    }
};