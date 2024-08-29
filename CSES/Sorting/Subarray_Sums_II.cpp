#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
ll pre[200005];
int main(){
  ll n, m;
  cin >> n >> m;
  pre[0] = 0;
  map<ll, int> mp;

  mp[0] = 1;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  ll ans = 0;
  for(int i = 1; i <= n; i++){
    pre[i] = pre[i-1]+a[i];
    ans += mp[pre[i]-m];
    mp[pre[i]]++;
  }
  cout << ans;
}