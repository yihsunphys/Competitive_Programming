#include <bits/stdc++.h>    
using namespace std;
int n;
long long maxRectangle(vector<int> h) {
  stack<pair<int, int>> stk;
  h.push_back(0);
  long long ans = 0;
  for(int i = 0; i < h.size(); i++){
    while(stk.size() && stk.top()>h[i]){
      int corner = stk.top().second;
      ans = max(ans, 1LL * stk.top().first * (i-corner));
    }
  }
}
long long maxRectangle(vector<int> h) {
  h.emplace_back(0);
  stack<pair<int, int>> STK;
  long long ans = 0;
  for (int i = 0; i < (int)h.size(); ++i) {
    int corner = i;
    while (STK.size() && STK.top().first >= h[i]) {
      corner = STK.top().second;
      ans = max(ans, 1LL * (i - corner) * STK.top().first);
      STK.pop();
     }
  STK.emplace(h[i], corner);
}
return ans;
}
int main() {
  while(cin >> n){
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << maxRectangle(v) << '\n';
  }
}