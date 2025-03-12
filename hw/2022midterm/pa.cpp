#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005], pre[100005], sum[100005];
int main(){
  int n;
  cin >> n;
  pre[0] = 0;
  sum[0] = 0;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a, a+n);
  for(int i = 1; i <= n; i++){
    pre[i] = pre[i-1]+a[i];
    sum[i] = sum[i-1]+pre[i];
  }
  cout << sum[n];
}