#include <bits/stdc++.h>
using namespace std;
int a[200005];
int idx[200005];
int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];   
    idx[a[i]] = i;
  }
  int ans = 1;
  for(int i = 1; i < n; i++) {
    if(idx[i+1] < idx[i]) ans++;
  }
  //cout << ans;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    int tmp = 0;
    int tmp2 = 0;
    int l = min(a[x]-1, a[y]-1);
    int r = min(n-1, max(a[x]+1, a[y]+1));
    if(r-l>100) {
        for(int j = l; j <= l+10; j++) {
          if(idx[j+1] < idx[j]) tmp++; 
        } 
        for(int j = r-10; j <= r; j++) {
          if(idx[j+1] < idx[j]) tmp++; 
        } 
        idx[a[x]] = y; idx[a[y]] = x;
        int z = a[x]; a[x] = a[y];a[y] = z; 
        for(int j = l; j <= l+10; j++) {
          if(idx[j+1] < idx[j]) tmp2++;
        } 
        for(int j = r-10; j <= r; j++) {
          if(idx[j+1] < idx[j]) tmp2++; 
        } 
    }
    else{
        for(int j = l; j <= r; j++) {
          if(idx[j+1] < idx[j]) tmp++;
        } 
        idx[a[x]] = y; idx[a[y]] = x;
        int z = a[x]; a[x] = a[y];a[y] = z; 
        for(int j = l; j <= r; j++) {
          if(idx[j+1] < idx[j]) tmp2++;
        } 
    }
    ans += tmp2-tmp;
    cout << ans << '\n';
  }
}