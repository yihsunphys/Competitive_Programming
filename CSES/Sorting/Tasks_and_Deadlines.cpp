#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
int main() {
  int n;
  cin >> n;
  ll sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    int x; cin >> x;
    sum += x;
  }
  sort(a, a+n);
  ll pre = 0;
  for(int i = 0; i < n; i++) {
    pre += a[i]*(n-i);
  }
  cout << sum-pre;
}