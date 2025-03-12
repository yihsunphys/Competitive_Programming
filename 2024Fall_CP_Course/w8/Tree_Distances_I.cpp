// 求每個點的最長路徑
// node x 的最長路徑有兩個可能:

// 最長路徑往child方向走
// 最長路徑往parent方向走
// parent的最長路徑+1
// 但parent的最長路徑有可能也經過x，那就要取parent的第二長路徑

// 演算法步驟:

// step1: 先算出每個點往child方向的最長和第二長並記錄
// step2: 對每個child x, 檢查每個點的最長路徑是否經過x,
// 是則x的最長路徑 = max(往child方向最長路徑, parent的第二長路徑+1)
// 否則 = parent的最長路徑+1
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
	    c[u] = x; // 紀錄最長路徑經過哪個child
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
