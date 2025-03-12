#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int> 
#define F first 
#define S second
pii a[5005];
int main(){
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a+n);
  ll tmp = 0;
  for(int i = 0; i < n; i++){
    if(a[i].F>=k) break; 
    int l = i+1, r = n-1;
    while(l<r){
      ll sum = (a[l].F+a[r].F+a[i].F);
      if (sum== k){
        int ans[3] = {a[i].S, a[l].S, a[r].S};
        sort(ans, ans+3);
        for(int i = 0; i < 3; i++ ) cout << ans[i]+1 << " ";
        return 0;
      }
      else if(sum<k) l++;
      else r--;
    }
  }
  cout << "IMPOSSIBLE";
}