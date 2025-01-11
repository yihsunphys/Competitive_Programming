#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[1000]={};
  while(n--) {
    int x;
    cin >> x;
    for(int i = 0; i < x; i++) {
      cin >> a[i];
    }
      int sum = 0;
      int cnt = 0;
      for(int i = 0; i < x-1; i++){
        if(sum + a[i] < a[i +1]) {
          cnt++;
          sum += a[i];
        }
      }
    cout << cnt+1 << '\n';
  }
}
