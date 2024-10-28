#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define TWO_MOD_INV  500000004
ll sum(ll start, ll end){ 
  return ((((end - start + 1) % MOD) * ((start + end) % MOD) % MOD) * TWO_MOD_INV % MOD
}
int main() {
  ll n;
  cin >> n;
  ll tot = 0;
  ll i = 1;
  while(i <= n){
    ll num = n/i;
    ll last_same = n/num;
    tot = (tot+num*sum(i, last_same))%MOD;
    i = last_same+1;
  }
  cout << tot << '\n';
}