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