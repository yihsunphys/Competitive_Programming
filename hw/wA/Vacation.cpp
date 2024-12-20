#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct st{
  int a, b, c;
};
int main(){
  int n;
  cin >> n;
  vector<vector<ll>> act(n+1, vector<ll>(3, 0));
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 3; j++)
      cin >> act[i][j]; 
  }
  vector<vector<ll>> dp(n+1, vector<ll>(3, 0));
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 3; j++){
      dp[i][j] = max(dp[i-1][(j+1)%3]+act[i][j], dp[i-1][(j+2)%3]+act[i][j]);
    }
  }
  ll ans = max(dp[n][0], dp[n][1]);
  ans = max(dp[n][2], ans);
  cout << ans;
}