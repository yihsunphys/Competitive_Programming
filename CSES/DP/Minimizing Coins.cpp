#include <bits/stdc++.h>
using namespace std;
int a[105];
int dp[1000005];
int main() {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for(int i = 1; i <= k; i++) {
    for(int j = 0; j < n; j++) {
      if(i-a[j] >= 0 && dp[i-a[j]]!=-1)
        if(dp[i] == -1) dp[i] = dp[i-a[j]]+1; 
        else dp[i] = min(dp[i-a[j]]+1, dp[i]);
    }
  }
  cout << dp[k];
}