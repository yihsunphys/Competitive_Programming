#include <bits/stdc++.h>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  // 三種constructor
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* mergeKLists(vector<ListNode*> lists); 

//方法: 每個list都放進priority queue 以第一個元素做排序
//1.初始化
struct CMP{
  bool operator()(ListNode*a, ListNode*b) const{ return a->val> b->val; }
};
priority_queue<ListNode *, vector<ListNode*>, CMP> PQ;
void initPQ(vector<ListNode*> &lists) {
  decltype(PQ)().swap(PQ);
  for(auto nd: lists)
  if(nd) PQ.emplace(nd);
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
  initPQ(lists);
  ListNode *root = nullptr;
  ListNode **cur = &root;
  while (PQ.size()) {
    auto nd = PQ.top();
    PQ.pop();
    *cur = nd;
    cur = &nd->next;
    if (*cur) PQ.emplace(*cur);
  }
 return root;
}
//不使用額外空間
ListNode *mergeKLists(vector<ListNode *> &lists) {
  auto iter = remove_if(lists.begin(), lists.end(), [](auto x) { return !x; });
  lists.erase(iter, lists.end());
  make_heap(lists.begin(), lists.end(), CMP());
  ListNode *root = nullptr;
  ListNode **cur = &root;
  while (lists.size()) {
    auto nd = lists.front();
    pop_heap(lists.begin(), lists.end(), CMP());
    lists.pop_back();
    *cur = nd;
    cur = &nd->next;
    if (*cur) {
      lists.emplace_back(*cur);
      push_heap(lists.begin(), lists.end(), CMP());
    }
  }
 return root;
}



