#include <bits/stdc++.h>
using namespace std;

int t, n, k;
long long a[10005], b[10005], c[10005], tmp[10005];
bool race(int day) {
  for(int i = 0; i < n; i++){
    tmp[i] = a[i] + c[i]*day;
  }
  sort(tmp, tmp+n);
  for(int i = 0; i < k; i++){
    if(tmp[n-k+i] <= b[i]) return 0;
  }
  return 1;
}
int main(){
  cin >> t;
  while(t--){
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      cin >> c[i];
    }
    for(int i = 0; i < n; i++) {
      cin >> b[i];
    }
    sort(b, b+n);
    int l = 0, r = 1e9;
    while(l <= r) {
      int mid = (l+r)/2; //cout << "mid = " <<mid << '\n';
      if (race(mid) == 0)  l = mid+1;
      else r = mid-1;
    }
    if(l >= 1e9) cout << -1 << '\n';
    else cout << l << '\n';
  }
}