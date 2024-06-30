#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[100005]; //屬於哪個集合?
vector<pair<int,int>> new_road;
int find(int x) { //find set
  return p[x] == x ? x: p[x] = find(p[x]);
}
int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    p[i] = i;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if(find(a) != find(b)) {
        p[find(a)] = p[find(b)]; //union
    }
  }
  for(int i = 2; i <= n; i++) {
    if(find(1)!= find(i)) {
        new_road.push_back({find(1), i});
        p[find(i)] = p[find(1)]; //union
    }
  }
  cout << new_road.size() << '\n';
  for(auto it: new_road)
    cout << it.first << " " << it.second << '\n';
}
//並查集