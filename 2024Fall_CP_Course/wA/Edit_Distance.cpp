#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int main(){
  string s1, s2;
  cin >> s1 >> s2;
  int n1 = s1.size(), n2 = s2.size();
  for(int i = 0; i <= n1; i++)
    dp[i][0] = i;
  for(int i = 0; i <= n2; i++)
    dp[0][i] = i;
  for(int i = 1; i <= n1; i++){
    for(int j = 1; j <= n2; j++){
      if(s1[i-1] == s2[j-1]){
        dp[i][j] = dp[i-1][j-1];
      }
      else{
        dp[i][j] = dp[i-1][j-1] + 1;
        dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
        dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
      }
    }
  }
  cout << dp[n1][n2];
}

