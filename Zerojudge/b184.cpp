#include <bits/stdc++.h>
using namespace std;
int w[105], v[105];
int dp[105][105];
int n;
int main() {
  while(cin >> n){
    for(int i = 0; i < n; i++) {
      cin >> w[i] >> v[i];
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j <= 100; j++) {
        if(w[i] > j) dp[i+1][j] = dp[i][j];
        else
          dp[i+1][j] = max(dp[i][j], v[i] + dp[i][j-w[i]]);
      }
    }
    cout << dp[n][100] << "\n";
  }
}
