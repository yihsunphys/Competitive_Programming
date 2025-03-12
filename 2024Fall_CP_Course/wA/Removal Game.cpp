// 定義 dp[l][r]：當數列範圍為 [l,r] 時，第一玩家能獲得的最大得分
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  vector<vector<ll>> dp(n, vector<ll>(n));
  for(int i = 0; i < n; i++)
    cin >> dp[i][i];
  for(int i = 0; i < n-1; i++)
    dp[i][i+1] = max(dp[i][i], dp[i+1][i+1]);
  for(int i = 3; i <= n; i++){
    for(int j = 0; j <= n-i; j++){
      int l = j, r = j+i-1; 
      dp[l][r] = max(dp[l][l]+min(dp[l+2][r], dp[l+1][r-1])
      ,dp[r][r]+min(dp[l][r-2], dp[l+1][r-1]));  
    }
  }
  cout << dp[0][n-1] << '\n';
}