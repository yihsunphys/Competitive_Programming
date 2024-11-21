#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> Tree(200005);
vector<int> level(200005);
void dfs(int u, int parent){
  if(parent == -1) level[u] = 0;
  else level[u] = level[parent]+1;
  for(auto v: Tree[u]){
    if(v == parent) continue;
    dfs(v, u);
  }
}
int main(){
  cin >> n; 
  for(int i = 0; i < n-1; i++){
    int u, v;
    cin >> u >> v;
    Tree[u].push_back(v);
    Tree[v].push_back(u);
  }

  dfs(1, -1);
  int a = max_element(level.begin(), level.end()) - level.begin();
  dfs(a, -1);
  int b = max_element(level.begin(), level.end()) - level.begin();
  cout << level[b] << '\n';
}