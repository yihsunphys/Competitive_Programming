#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll fact[1000005], inv[1000005];
ll fastpow(ll a, ll b){
  if(b == 0) return 1;
  ll tmp = fastpow(a, b/2);
  if(b&1) return (tmp*tmp%mod)*a%mod;
  return tmp*tmp%mod;
}
int main(){
  int n;
  cin >> n;
  fact[0] = 1; inv[0] =1;
  for(int i = 1; i <= 1000000; i++){
    fact[i] = fact[i-1]*i%mod;
    inv[i] = fastpow(fact[i], mod-2);
  }
  while(n--){
    ll a, b;
    cin >> a >> b;
    ll ans = ((fact[a]*inv[b])%mod*inv[a-b])%mod; 
    cout << ans << '\n';
  }
}