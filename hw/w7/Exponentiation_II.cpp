// 費馬小定理
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll fast_pow(ll a, ll b, ll m){
  ll res = 1; 
  while(b){
    if(b&1) res = res*a%m;
    b>>=1;
    a = a*a%m;    
  }
  return res;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = fast_pow(b, c, MOD-1);
    cout << fast_pow(a, x, MOD) << endl;
  }
}