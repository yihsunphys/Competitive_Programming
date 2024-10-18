#include <bits/stdc++.h>
using namespace std;    
int n[100005], k[100005], ans[100005];
int main(){
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> n[i];
  }
  for(int i = 0; i < t; i++) {
    cin >> k[i];
  }
  ans[0] = 1;
  for(int i = 1; i < 100005; i++) {
    ans[i] = (ans[i-1]*2)%1000000007;
  }
  for(int i = 0; i < t; i++) {
    cout << ans[k[i]] << endl;
  }
}