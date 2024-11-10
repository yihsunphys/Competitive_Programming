#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int> 
#define F first 
#define S second

struct node{
  int val;
  node *prev, *next;
};

int main(){
  int n;
  cin >> n;
  node *head = new node;
  node *tail = new node;
  head->next = tail;
  tail->prev = head;
  node *cur = new node;
  cur->val = 0; cur->prev = head; cur->next = tail;
  for(int i = 1; i <= n; i++){
    node *new_node = new node;
    new_node->val = i;  
    char op;
    cin >> op;
    if(op ==  'L'){
      cur->prev->next = new_node;
      new_node->prev = cur->prev;
      cur->prev = new_node;
      new_node->next = cur;
    }
    else{
      cur->next->prev = new_node;
      new_node->next = cur->next;
      cur->next = new_node;
      new_node->prev = cur;
    }
    cur = new_node;
  }
  node *temp = head->next;
  while(temp != tail){
    cout << temp->val << " ";
    temp = temp->next;
  }
}