#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200005];
int n, k;
bool is_possible(ll mid){
  ll sum = 1;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(a[i]>mid) return 0;  
    if(sum+a[i] <= mid) sum+=a[i];
    else{
      cnt++;
      sum = a[i];
    }
  }
  if(cnt < k) return 1;
  else return 0;
}
int main(){
  cin >> n >> k;
  for(int i = 0; i < n; i++)
   cin >> a[i];
  ll l = 0, r = 2e14;
  while(l <= r){
    ll mid = (l+r)/2;
    if(is_possible(mid)) r = mid-1;
    else l = mid+1;
  }
  cout << l;
}