#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Tree(200005);
vector<int> firstmax(200005), secondmax(200005), c(200005);
// 先算出每個點的最長路徑和次長路徑
void dfs1(int u, int parent){
  firstmax[u] = 0;
  secondmax[u] = 0;
  for(auto x: Tree[u]){
    if(x == parent) continue;
    dfs1(x, u);
    if(firstmax[x]+1 > firstmax[u]){
	  secondmax[u] = firstmax[u];
	  firstmax[u] = firstmax[x]+1;
	  c[u] = x;
	}
	else {
	  secondmax[u] = max(secondmax[u], firstmax[x]+1);
	}
  }
}
// top->down 算真正的最長路徑和次長路徑
void dfs2(int u, int parent){
  for (auto x: Tree[u]){
	if(x == parent) continue;
    if(c[u] == x){
	  if(secondmax[u]+1 > firstmax[x]){
		secondmax[x] = firstmax[x];
		firstmax[x] = secondmax[u]+1;
		c[x] = u;
	  }
	  else secondmax[x] = max(secondmax[x], secondmax[u]+1);
	}
	else {
	  secondmax[x] = firstmax[x];
	  firstmax[x] = firstmax[u]+1;
	  c[x] = u;   
	}
	dfs2(x, u);
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
  dfs1(1, -1);
  dfs2(1, -1);
  for(int i = 1; i <= n; i++){
    cout << firstmax[i] << " ";
  }
}
