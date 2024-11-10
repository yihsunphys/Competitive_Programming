#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  queue<int> q;
  priority_queue<int, vector<int>, greater<int>> pq;
  while(n--){
    int op;
    cin >> op;
    if(op == 1){
      int num;
      cin >> num;
      q.push(num);
    }
    else if(op == 2){
      if(!pq.empty()){
        cout << pq.top() << '\n';
        pq.pop();
      }
      else{
        cout << q.front() << '\n';
        q.pop();
      }
    }
    else {
      while(!q.empty()){
        pq.push(q.front());
        q.pop();
      }
    }
  }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  while(cin>>n){
    priority_queue<int, vector<int>, greater<int>> pq;
    queue<int> q;
    while(n--){
      int x;
      cin >> x;
      if(x == 1) {
        int num;
        cin >> num;
        q.push(num);
      }
      else if(x == 2){
        if(pq.size()){
          cout << pq.top() << endl;
          pq.pop();
        }
        else {
          cout << q.front() << endl;
          q.pop();
        }
      }
      else {
        while(q.size()){
          pq.push(q.front());
          q.pop();
        }
      }
    }
  }
}