#include <bits/stdc++.h>    
using namespace std;
#define MAXN 1e6+10
#define ll long long
int n; 
int main() {
  vector<ll> cnt(MAXN); //cnt[i] = i有幾個
  vector<ll> dp(MAXN); //配對的最大公因數為i的有多少對
  cin >> n;
  for(int i = 0; i < n; i++){
    int tmp; cin>>tmp;
    cnt[tmp]++;
  }  
  for(int i = MAXN-1; i>=1; i--){
    ll x = 0, y = 0; 
    for(int j = i; j < MAXN; j+=i){
      x+=cnt[j];
      y+=dp[j];
    }
    dp[i] = (x*(x-1)/2)-y;
  }

  cout << dp[1] << "\n";
}