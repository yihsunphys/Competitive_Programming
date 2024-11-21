#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Tree(200005);
vector<int> level(200005);
void dfs(int u, int parent = -1){
  if(parent == -1) level[u] = 0;
  else level[u] = level[parent]+1;
  for(auto v: Tree[u]){
    if(v == parent) continue;
    dfs(v, u);
  }
}
int main(){
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i < n; i++){
    int u, v;
    cin >> u >> v;
    Tree[u].push_back(v);
    Tree[v].push_back(u);
  }
  for(int i = 1; i <= n; i++){
    dfs(i);
    int ans = max_element(level.begin(), level.end()) - level.begin();
    cout << level[ans] << ' ';
  }
}