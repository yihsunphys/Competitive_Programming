#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
ll pre[200005];
ll pmod[200005];
int main() {
  int n;
  cin >> n;
  pre[0] = 0;
  memset(pmod, 0, sizeof(pmod));
  pmod[0]=1;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i-1]+a[i];
    pmod[(pre[i]%n+n)%n]++;
  }
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    ans+=pmod[i]*(pmod[i]-1)/2;
  }
  cout << ans;
}