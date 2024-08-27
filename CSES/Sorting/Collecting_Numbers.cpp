#include <bits/stdc++.h>
using namespace std;
int a[200005];
int idx[200005];
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    idx[a[i]] = i;
  }
  int ans = 1;
  for(int i = 1; i < n; i++){
    if(idx[i+1] < idx[i]) ans++;
  }
  cout << ans;
}