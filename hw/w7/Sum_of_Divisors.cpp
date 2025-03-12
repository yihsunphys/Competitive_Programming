#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int inv;
ll sum(ll start, ll end){
  return (((end-start+1)%MOD)*((end+start)%MOD))%MOD*inv%MOD;
}
ll fastpow(ll x, ll y){
  if(y == 0) return 1;
  ll tmp = fastpow(x, y/2)%MOD;
  if(y&1) return ((tmp*tmp)%MOD)*x%MOD;
  else return (tmp*tmp)%MOD;
}
int main(){
  ll n;
  cin >> n;
  ll i = 1;
  ll ans = 0;
  inv = fastpow(2, MOD-2);
  while(i<=n){
    ll num = n/i;
    ll last_same = n/num;
    ll tot = sum(i, last_same);
    ans = (ans + tot*num)%MOD;
    i = last_same+1;
  }
  cout << ans;
}