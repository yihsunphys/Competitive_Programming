#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
ll n;
bool is_possible(ll sum, int k) {
  ll tmp = 0; 
  ll num = 0;
  for(int i = 0; i < n; i++) {
    tmp+=a[i];
    if(a[i] > sum) return false;
    if(tmp > sum) {
      tmp = 0;
      num++;
      i--;
    }
  }
  if(num < k) return true;
  else return false;
}
int main() {
  ll k;
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  ll l = 0, r = 2e14;
  while(l<r){
    ll mid = (l+r)/2;
    if(is_possible(mid, k)){
        r = mid; 
    }
    else l = mid+1;
  }
  cout << l;
}