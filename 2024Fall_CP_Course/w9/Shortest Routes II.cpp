// floyd_warshall
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define INF (LLONG_MAX/2)
#define ll long long
void floyd_warshall(vector<vector<ll>> &G, int n){
  for(int k = 1; k <= n; k++)
    for(int u = 1; u <= n; u++)
      for(int v = 1; v <= n; v++)
        G[u][v] = min(G[u][v], G[u][k] + G[k][v]);
}
int main(){
  ll n, m, q, a, b, c;
  cin >> n >> m >> q;
  vector<vector<ll>> G(n+1, vector<ll>(n+1, INF));
  for(int i = 1; i <= n; i++) G[i][i] = 0;
  for(int i = 0; i < m; i++){
    cin >> a >> b >> c;
    G[a][b] = min(G[a][b], c);
    G[b][a] = min(G[b][a], c);
  }
  floyd_warshall(G, n);
  while(q--){
    cin >> a >> b;
    if(G[a][b] == INF) cout << -1 << endl;
    else cout << G[a][b] << endl;
  }
}
