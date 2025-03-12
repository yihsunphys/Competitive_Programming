// dp[0][u] u 為白色 dp[1][u] u 為黑色 
// dp[0][u]= v∈子節點 sigma(dp[0][v]+dp[1][v])
// dp[1][u]= v∈子節點 sigma(dp[0][v])
// 使用 DFS 遍歷樹，從根節點開始遞歸地計算每個子節點的 DP 狀態。
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int dfs(int now, int p, int color, vector<vector<int>>& G, vector<vector<int>>& dp){
  if(G[now].size()==1 && G[now][0]==p) return 1;
  if(dp[color][now]) return dp[color][now];
  dp[color][now] = 1;
  for(auto v: G[now]){
    if(v == p) continue;
    int child = dfs(v, now, 0, G, dp) + (color==0?dfs(v, now, 1, G, dp):0);
    dp[color][now] = ((ll)dp[color][now]*child)%MOD;
  }
  return dp[color][now];
}
int main(){
  int n, u, v;
  cin >> n;
  vector<vector<int>> G(n+1), dp(2, vector<int>(n+1));
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  cout << (dfs(1, -1, 0, G, dp)+dfs(1, -1, 1, G, dp))%MOD << "\n";
}

