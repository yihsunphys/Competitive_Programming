#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  queue<int> q;
  for(int i = 1; i <= n; i++) {
    q.push(i);
  }
  bool flag = 0;
  while(!q.empty()){
    int id = q.front();
    q.pop();
    if(flag) cout << id << " ";
    else q.push(id); 
    flag = !flag;
  }
}