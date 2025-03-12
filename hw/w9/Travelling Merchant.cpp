// P−TR≥0
// 對每個邊 p-tr 檢查是否有負環
#include <bits/stdc++.h>
using namespace std;  
#define ll long long 
const ll INF = LLONG_MAX / 2;

void floyd_warshall(vector<vector<ll>>& G){
  int n = G.size()-1;
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
          G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
}
int main(){
  ll n, m, k, u, v, w;
  cin >> n >> m >> k;
  vector<vector<ll>> G(n+1, vector<ll>(n+1, INF));
  vector<vector<ll>> G2(n+1, vector<ll>(n+1, INF));
  vector<vector<ll>> b(n+1, vector<ll>(k+1));
  vector<vector<ll>> s(n+1, vector<ll>(k+1));
  vector<vector<ll>> p(n+1, vector<ll>(n+1));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= k; j++){
      cin >> b[i][j] >> s[i][j];
    }
  }
  for(int i = 0; i < m; i++){
    cin >> u >> v >> w;
    G[u][v] = w;
  }
  floyd_warshall(G);
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      for(int x = 1; x <= k ; x++)
        if(s[j][x] != -1 && b[i][x] != -1)
        p[i][j] = max(p[i][j], s[j][x]-b[i][x]);
    
  ll l = 1, r = 1e9;
  while(l<=r){
    ll mid = (l+r)/2; 
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        G2[i][j] = G[i][j]==INF?INF:mid*min(G[i][j], INF/mid)-p[i][j];
      }
    }
    bool has_nagativecycle = false;
    floyd_warshall(G2);
    for(int i = 1; i <= n; i++){
      if(G2[i][i] <= 0){
        has_nagativecycle = true;
        break;
      }
    }
    if(has_nagativecycle) l = mid+1;
    else r = mid-1;
  }
  cout << r << "\n";
}