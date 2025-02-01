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
private:
    struct cmp{ bool operator()(ListNode *a, ListNode *b){ return a->val>b->val; }};
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
    void init(vector<ListNode*>& lists){
        decltype(pq)().swap(pq); //清空pq
        for(auto nd: lists){
            if(nd) pq.emplace(nd);
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        init(lists);
        ListNode* root = nullptr;
        ListNode** cur = &root;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            *cur = it;
            cur = &it->next;
            if(*cur) pq.emplace(*cur);
        }
        return root;
    }
};