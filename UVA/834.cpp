#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  while(cin >> a >> b){
      printf("[%d;", a/b);
      a %= b;
      swap(a, b);
      bool first  = true;
      while(b != 0) {
        if(first) {
          cout << a/b;
          first = false;
        }
        else
          cout << ',' << a/b;
        a %= b;
        swap(a, b); 
      }
      cout<<"]\n";
  }
}
