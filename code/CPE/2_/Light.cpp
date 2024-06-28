#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while(cin >> n){
    if(n ==0) break;
    int num = sqrt(n);
    if(num*num == n) cout << "yes\n";
    else cout << "no\n";
  }
}
