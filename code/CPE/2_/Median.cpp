#include <bits/stdc++.h>
using namespace std;
int main() {
  multiset<int> s;
  int num;
  while(cin >> num) {
    s.insert(num);
    int n = s.size();
    auto it = s.begin();
    advance(it, n/2);
    if(n%2 == 0){
      cout << (*it-- + *it) / 2 << '\n';
    }
    else {
      cout << *it <<'\n';
    }
  }
}
