#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll> 
pll extended_gcd(ll x, ll y){
  if(y==0) return {1,0};
  auto [x_, y_] = extended_gcd(y, x%y);
  return {y_, x_-x/y*y_};
}
int main(){
  int t;
  cin >> t;
  while(t--){
    ll a[3], b[3], M = 1;
    for(int i = 0; i < 3; i++){
      cin >> a[i] >> b[i];
      M *=  a[i];
    }
    ll res = 0;
    for(int i = 0; i < 3; i++){
      ll m = M/a[i];
      auto [x, y] = extended_gcd(m, a[i]);
      ll t = (x%a[i]+a[i])%a[i];
      res = (res+b[i]*m*t)%M;
    }
    cout << res << '\n';
  }
}