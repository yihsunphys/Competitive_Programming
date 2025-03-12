#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for(int i = 0; i < n; i++)
    cin >> v[i];
  pair<int, int> dp[1<<n];
  dp[0] = {1, 0};
  for(int mask = 1; mask < (1<<n); mask++){
    dp[mask] = {INT_MAX, 0};
    for(int i = 0; i < n; i++){
      if(mask&(1<<i)){ // 要載這個人
        int pre = mask^(1<<i);
        auto [ride, current_w] = dp[pre];
        if(current_w+v[i] <= x)
          dp[mask] = min(dp[mask], {ride, current_w+v[i]});
        else
          dp[mask] = min(dp[mask], {ride+1, v[i]});
      }
    }
  }
  cout << dp[(1<<n)-1].first << '\n';
}