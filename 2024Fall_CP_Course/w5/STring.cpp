#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  stack<char> stk;
  int len = s.size();
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'T') 
      if(!stk.empty())
        if(stk.top() == 'S') {
          len-=2;
          stk.pop();
        }
        else stk.push(s[i]);
      else stk.push(s[i]);
    else stk.push(s[i]);
  } 
  cout << len << '\n';
}