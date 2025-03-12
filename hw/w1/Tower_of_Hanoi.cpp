#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ans;
int sol = 0;
void Honoi(int n, int a, int b, int c) {
  if(n == 0) return;
  Honoi(n-1, a, c, b);
  ans.push_back({a, c});
  sol++;
  Honoi(n-1, b, a, c);
}
int main() {
  int n;
  cin >> n;
  Honoi(n, 1, 2, 3);
  cout << sol << '\n';
  for(auto it: ans)
    cout << it.first << " " << it.second << '\n';
}