#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
const int MOD_INV_2 = 5e8+4;
int main(){
  int n;
  cin >> n;
  int sum = n*(n+1)/2;
  if(sum%2) {
    cout << "0\n";
    return 0;
  }       
  int target = sum/2;
  vector<int> dp(target+1);
  dp[0] = 1;
  for(int i = 1; i <= n; i++)
    for(int j = target; j>=i; j--)
      dp[j] = (dp[j] + dp[j-i])%MOD;

  cout << (ll)dp[target]*MOD_INV_2%MOD;
}

