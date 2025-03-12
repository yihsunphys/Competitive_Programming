// 找最大路徑版本的bellman_ford 可偵測正環
// 檢測是否有正環位於解答路徑上
// G1, G2分別為正向邊與反向邊的鄰接表
// 檢測是否有正環位於解答路徑上
// G1, G2分別為正向邊與反向邊的鄰接表
#include <bits/stdc++.h>
using namespace std;
#define INF (LLONG_MAX/2)
#define ll long long
struct Edge{
  int u, v, w;
};
void dfs(int idx, vector<bool> &vis, vector<vector<int>> &G){
  vis[idx] = true;
  for(auto x: G[idx]){
    if(vis[x]) continue;
    dfs(x, vis, G);
  }
}

int main(){
  int n, m, u, v, w;
  cin >> n >> m;
  vector<vector<int>> G1(n+1), G2(n+1);
  vector<Edge> E(m);
  vector<bool> vis1(n+1), vis2(n+1);
  for(int i = 0; i < m; i++){
    cin >> E[i].u >> E[i].v >> E[i].w;
    G1[E[i].u].push_back(E[i].v);
    G2[E[i].v].push_back(E[i].u);
  }
  // 用於檢測點是否在解答路徑上
  dfs(1, vis1, G1);
  dfs(n, vis2, G2);
  vector<ll> D(n+1, -INF);
  D[1] = 0;
    for(int i = 0; i < n; i++){
        bool update = false;
        for(auto [u, v, c] : E){
            if(D[v] < D[u]+c){
                D[v] = D[u]+c;
                update = true;
                if(i==n-1 && vis1[v] && vis2[v]){
                    cout << "-1\n";
                    return 0;
                }
            }
        }
        if(!update) break;
    }
    cout << D[n] << "\n";
    return 0;
}