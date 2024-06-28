#include <bits/stdc++.h>
using namespace std;
int a[55][55];
int main() {
  int Case;
  cin >> Case;
  while(Case--) {
    int r, c, n;
    cin >> r >> c >> n;
    cout << r << " " << c << " " << n << '\n';
    string s;
    for(int i = 0; i < r; i++) {
      cin >> s;
      for(int j = 0; j < c; j++)
        a[i][j] = s[j];
    }
    while(n--) {
      int r1, c1;
      cin >> r1 >> c1;
      int idx = 1;
      bool same = true;
      int ans = 1;
      while(same) {
        for(int i = r1-idx; i <= r1 +idx; i++) {
          for(int j = c1-idx; j <= c1 + idx; j++) {
            if(i<0 || i>=r || j<0 || j>=c) {same = false;break;}
            if(a[i][j] != a[r1][c1]) {same = false;break;}
          }
          if(!same) break;
        }
        if(same) {idx++;ans+=2;}
      }
      cout << ans << '\n';
    }
  }
}
