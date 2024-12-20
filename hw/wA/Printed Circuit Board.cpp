#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int main(){
  int n;
  cin >> n;
  vector<pii> v(n);
  for(int i = 0; i < n; i++)
    cin >> v[i].first >> v[i].second; 
  sort(v.begin(), v.end());
  vector<int> dp;
  for(auto [i, j]: v){
    // 找<=j的最大值
    auto it = lower_bound(dp.begin(), dp.end(), -j);
    if(it == dp.end()) dp.push_back(-j);
    else *it = -j;
  }
  cout << dp.size();
}