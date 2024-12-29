#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
int y, p, q, m;
ll a[20000005];
ll pre[20000005];
ll ans[20000005];
int main(){
  cin >> n >> k;
  cin >> y >> p >> q >> m;
  a[1] = y;
  pre[0] = 0;
  pre[1] = y;
  for(int i = 2; i <= n; i++){
    a[i] = ((a[i-1]*p) + q)%m;
    pre[i] = pre[i-1] + a[i];
  }

  deque<int> maxq, minq;
  maxq.push_back(0);
  minq.push_back(0);
  
  for(int i = 1; i < n; i++){ 
    // 維護遞增單調隊列
    while(!maxq.empty() && maxq.front() <= i-k)
      maxq.pop_front();
    while(!maxq.empty() && pre[maxq.back()]<pre[i])
      maxq.pop_back();
    maxq.push_back(i);
    
    // 維護遞減單調隊列
    while(!minq.empty() && minq.front() <= i-k)
      minq.pop_front();
    while(!minq.empty() && pre[minq.back()]>pre[i])
      minq.pop_back();
    minq.push_back(i);
    
    ans[i+1] = max(abs(pre[i+1]-pre[maxq.front()]), abs(pre[i+1]-pre[minq.front()]));
  }
  ans[1] = pre[1];
  
  ll x = ans[1]*ans[1]*1LL;
  for(int i = 2; i <= n; i++){
    ll y = ans[i]*ans[i]*1LL;
    x^=y;
  }
  cout << x;
}