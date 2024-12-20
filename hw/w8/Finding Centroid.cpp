// 找樹重心
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree(200005); 
vector<int> siz;
int n;
int ans = -1;
void dfs(int u, int p = -1){
  siz[u] = 1;
  int mx_subsize = 0;
  for(auto x: tree[u]){
    if(x == p) continue;
    dfs(x, u);
    siz[u] += siz[x];
    mx_subsize = max(mx_subsize, siz[x]);  
  }
  mx_subsize = max(mx_subsize, n-siz[u]);
  if(mx_subsize <= n/2) ans = u;
}
int main(){
  cin >> n;
  for(int i = 0; i < n-1; i++){
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  for(int i = 1; i <= n; i++){
    siz.assign(n+1, 0);
    dfs(i);
    if(ans != -1){
      cout << ans << endl;
      break;
    } 
  }
}