#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[205];
ll tot = 0;
ll sum = 0;
ll mi = 10000000007;
int n;
void dfs(int i) {
  if(i == n) {
    mi = min(mi, abs(tot-2*sum));
    return;
  }
  sum += a[i];
  dfs(i+1);
  sum -= a[i];
  dfs(i+1);
}
int main() {
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    tot += a[i];
  }
  dfs(0);
  cout << mi;
}