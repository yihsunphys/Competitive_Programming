#include <bits/stdc++.h>
using namespace std;
struct st{
  bool up;
  int num;
};
st b[200005];
bool a[200005];
int main() {
  int t;
  cin >> t;
  while(t--){
    for(int i = 0; i < 200005; i++){
      a[i] = 0; 
    }
    int n, m;
    cin >> n >> m;
    char ch;
    for(int i = 0; i < m; i++){
      cin >> ch >> b[i].num;
      b[i].up = (ch == 'H');
    }
    stack<int> stk;
    for(int i = m-1; i >= 0; i--){ //從後面開始
      if(b[i].up){ //頭
        if(a[b[i].num] == 0){
          a[b[i].num] = 1;
          cout << b[i].num << " ";
        }
      }
      else{ //尾
        if(a[b[i].num] == 0){
          stk.push(b[i].num);
          a[b[i].num] = 1;
        }
      }
    }
    for(int i = 1; i <= n; i++) {
      if(a[i] == 0) cout << i << " ";
    }
    while(!stk.empty()){
      cout << stk.top() << " "; 
      stk.pop();
    }
    cout << '\n';
  }
}