// dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum(i,j))
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int n;
  cin >> n;
  vector<int> v(n+1);
  vector<ll> pre(n+1);
  vector<vector<ll>> dp(n+1, vector<ll>(n+1));
  for(int i = 1; i <= n; i++){
    cin >> v[i];
    pre[i] = pre[i-1] + v[i];
  }
  for(int len = 2; len <= n; len++){
    for(int i = 1; i <= n-len+1; i++){
      int l = i, r = i+len-1; 
      dp[l][r] = LLONG_MAX;
      for(int k = l; k < r; k++){
        dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]+pre[r]-pre[l-1]);
      }
    }
  }
  cout << dp[1][n] << '\n';
}