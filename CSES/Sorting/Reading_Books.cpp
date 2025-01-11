#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[200005];
int main() {
  int n;
  cin >> n;
  ll sum = 0;
  bool flag = 1;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a, a+n);
  for(int i = 0; i < n; i++){
    if(i == n-1) {
      if(sum > a[i]) flag = 0;
      else flag = 1;
    } 
    else sum += a[i];
  }
  ll ans = 0;
  if(flag) ans = a[n-1]*2;
  else ans = a[n-1]+sum;
  cout << ans;
}