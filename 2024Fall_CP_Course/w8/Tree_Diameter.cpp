// 求樹直徑
#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> Tree;
vector<int> level;
void dfs(int u, int parent=-1){
  if(parent == -1) level[u] = 0;
  else level[u] = level[parent]+1;
  for(auto v: Tree[u]){
    if(v == parent) continue;
    dfs(v, u);
  }
}
int main(){
  cin >> n; 
  Tree.assign(n+1, {});
  level.assign(n+1, {});
  for(int i = 0; i < n-1; i++){
    int u, v;
    cin >> u >> v;
    Tree[u].push_back(v);
    Tree[v].push_back(u);
  }

  dfs(1);
  int a = max_element(level.begin(), level.end()) - level.begin();
  dfs(a);
  int b = max_element(level.begin(), level.end()) - level.begin();
  cout << level[b] << '\n';
}