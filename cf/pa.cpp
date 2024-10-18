#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while(n--) {
    string a, b;
    cin >> a >> b;
    int pre = 0;
    bool flag = false;
    for(int i = 0; i < min(a.size(), b.size()); i++) {
      if(a[i] == b[i]) {
        pre++;
        flag = true;
      }
      else break;
    }
    int ans = pre + a.size() + b.size() - 2 * pre;
    cout << ans + flag << endl;    
  }
}