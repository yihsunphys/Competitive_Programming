#include <bits/stdc++.h>
using namespace std;
int n, a, b;
//int x[1000000005];
//int pre[200005];
vector<pair<int,int>> v;
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    //x[a]+=1; x[b]-=1;
    v.push_back({a, 1});
    v.push_back({b, -1});
  }
  int current = 0;
  int mx = 0;
  sort(v.begin(), v.end());
  for(auto it: v) {
    //pre[i] = pre[i-1] + x[i];
    current += it.second;
    mx = max(mx, current);
  }
  cout << mx << '\n';
}
//本來想直接開陣列算prefix sum 但太大了 可以改用vector