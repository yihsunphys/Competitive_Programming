#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main() {
  int n;
  while(cin >> n) {
    if(n == 0) break;
    int num = n;
    int cnt = 0;
    int idx = 0;
    while(n) {
      if(n & 1) cnt++;
      a[idx] = (n & 1); 
      idx++;
      n >>= 1;
    }
    cout << "The parity of ";
    for(int i = idx-1; i>=0; i--)
      cout<<a[i];
    
    printf(" is %d (mod 2).\n", cnt);
  } 
}
//位元運算
