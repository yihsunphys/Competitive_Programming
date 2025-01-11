#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int len, num;
  cin >> len >> num;
  set<int> light{0, len};
  multiset<int> path{len};
  for(int i = 0; i < num; i++) {
    int pos;
    cin >> pos;
    auto it1 = light.upper_bound(pos);
    auto it2 = it1; it2--;
    path.erase(path.find(*it1-*it2));
    path.insert(*it1-pos);
    path.insert(pos-*it2);
    light.insert(pos);
    auto ans = path.end(); ans--;
    cout << *ans << " ";
  }   
}