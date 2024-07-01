#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int> 
pii a[200005];
bool cmp(pii x, pii y) {
  return x.second < y.second;
}
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a+n, cmp);
  int ans = 0;
  int end = -1;
  for(int i = 0; i < n; i++) {
    if(a[i].first >= end) {
        ans++;
        end = a[i].second;
    }
    else continue;
  }
  cout << ans;
}
//最佳子結構: 優先選最早結束的