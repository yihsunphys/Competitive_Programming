#include <bits/stdc++.h>
using namespace std;
int machine[200005];
#define ll long long
int main() {
  ll n, t;
  cin >> n >> t;
  for(int i = 0; i < n; i++)
    cin >> machine[i];
  sort(machine, machine+n);
  ll l = 0, r = 1e18;
  while(l<r){
    ll mid = (l+r)/2;
    ll sum = 0;
    for(int j = 0; j < n; j++) {
      sum+=mid/machine[j];
      if(sum > t) break;
    }
    if(sum>=t){
      r = mid;
    }
    else{
      l = mid+1;
    }
  }
  cout << l;
}