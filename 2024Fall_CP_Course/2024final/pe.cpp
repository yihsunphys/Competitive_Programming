#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fastpow(ll base, ll exp, ll mod){
  if(exp == 0) return 1;
  ll tmp = fastpow(base, exp/2, mod)%mod;
  if(exp%2) return (((tmp*tmp)%mod)*base)%mod;
  else return (tmp*tmp)%mod;
}
ll stringMod(string num, ll mod){
  ll result = 0;
  for (char c : num) {
    result = (result * 10 + (c - '0')) % mod;
  }
  return result;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    string a, b;
    ll p;
    cin >> a >> b >> p;
    ll a_mod_p = stringMod(a, p);
    ll b_mod_p = stringMod(b, p-1);
    ll ans = fastpow(a_mod_p, b_mod_p, p);
    cout << ans << '\n';
  }
}