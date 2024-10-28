#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll extended_gcd(ll a, ll b, ll &x, ll &y){
  if(b == 0){
    x = 1, y = 0;
    return a;
  }
  ll x1, y1;
  ll g = extended_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    vector<ll> k(3), r(3);
    for(int i = 0; i < 3; i++)
      cin >> k[i] >> r[i];
    cout << crt(k, r) << '\n';
  }
}