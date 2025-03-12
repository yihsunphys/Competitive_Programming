#include <bits/stdc++.h>
using namespace std;

vector<int> toposort(int n, vector<vector<int>> G, vector<int> in){
  vector<int> ans;
  for(int i = 1; i <= n; i++){
    if(in[i] == 0) ans.push_back(i); 
  }
  for(int i = 0; i < ans.size(); i++){
    int u = ans[i];
    for(auto v: G[u]){
      if(--in[v] == 0) ans.push_back(v);
    }
  }
  return ans;
}
int main(){
  int n, m, u, v;
  cin >> n >> m;
  vector<vector<int>>G(n+1);
  vector<int> in(n+1, 0);
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    G[u].push_back(v);
    in[v]++;
  }
  vector<int> ans = toposort(n, G, in);
  if(ans.size() == n)
    for(auto e: ans)
      cout << e << " ";
  else cout << "IMPOSSIBLE\n";
}