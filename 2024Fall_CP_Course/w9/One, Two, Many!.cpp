#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int c, vector<int> &color, vector<vector<int>> G){
  if(color[u]) return color[u] == c;
  color[u] = c;
  for(auto v: G[u]){
    if(!dfs(v, 3-c, color, G)) return false;
  }
  return true;
}
int main(){
  int n, m, u, v;
  cin >> n >> m;
  vector<vector<int>> G(n+1);
  vector<int> color(n+1);
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  for(int i = 1; i <= n; i++){
    if(!color[i]){
      if(!dfs(i, 1, color, G)){
        cout << "MANY\n";
        return 0;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    cout << color[i] << " ";
  }
}