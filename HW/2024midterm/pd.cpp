#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int n, k;
int a[2000005];
int cnt[2000005];
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < n; i++){
    cin >> a[i];
    cnt[a[i]]++;
  }

  ll ans = 0;
  for(int i = 1; i <= 2000000; i++){
    int tot = 0;
    for(int j = i; j <= 2000000; j+=i){
      tot+= cnt[j];
      if(tot>=k) break;
    }
    if(tot>=k) ans += i;
  }
  cout << ans;
}