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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;
        ListNode* nxt;
        while(fast){
            fast = fast->next->next;
            nxt = slow->next;
            slow->next = pre;
            pre = slow;
            slow = nxt; 
        }
        int ans = 0;
        while(slow){
            ans = max(ans, slow->val+pre->val);
            slow = slow->next;
            pre = pre->next;
        }
        return ans;
    }
};