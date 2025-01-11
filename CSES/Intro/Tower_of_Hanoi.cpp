#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ans;
int count(int n, int a, int b, int c) {
  if(n == 1){
    ans.push_back({a, c});
    return 1;
  } 
  int step = 0;
  step+=count(n-1, a, c, b);
  step+=count(1, a, b, c);
  step+=count(n-1, b, a, c);
  return step;
}
int main() { 
  int n;
  cin >> n;
  cout << count(n, 1, 2, 3) << '\n';
  for(auto it: ans) {
    cout << it.first << " " << it.second << '\n';
  }
}