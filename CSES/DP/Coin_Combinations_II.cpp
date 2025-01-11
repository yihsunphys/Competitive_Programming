#include <bits/stdc++.h>
using namespace std;
int v[105];
long long dp[1000005];
int main() {
  int n, x;
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  dp[0] = 1;
  for(int j = 0; j < n; j++) {
    for(int i = 0; i <= x; i++) {
      if(i >= v[j]) {
        dp[i] += (dp[i-v[j]])%1000000007; 
      }
    }
  }
  cout << dp[x]%1000000007;
}
