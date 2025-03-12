#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
struct st{
  int a, b;
  ll x;
};
st f[100005];
bool cmp(st a, st b){
  return a.x < b.x;
}
// 是否能是所有函數值都<k
bool check(ll k){
  for(int i = 0; i < n; i++){
    f[i].x = (k-f[i].b)/f[i].a;
  }
  sort(f, f+n, cmp);
  for(int i = 0; i < n; i++){
    // cout << f[i].x << " ";
    if(f[i].x < i+1) return false;
  }
  return true;
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> f[i].a >> f[i].b;
  }

  ll l = 1, r = 1e15;
  while(l<=r){
    ll mid = (l+r)/2;
    if(check(mid)) r = mid-1;
    else l = mid+1;
  }
  cout << l;
}