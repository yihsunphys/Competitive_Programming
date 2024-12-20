#include <bits/stdc++.h>
using namespace std;
#define INF (LLONG_MAX-INT_MAX)
#define ll long long
#define pii pair<int, int>
#define pli pair<ll, int>

vector<ll> dijkstra(const vector<vector<pii>>& G, int s){
  int n = G.size();
  vector<ll> dist(n, INF);
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  dist[s] = 0;
  pq.push({0, s});
  while(!pq.empty()){
    auto [d, v] = pq.top();
    pq.pop();
    if(dist[v] < d) continue;
    for(auto x: G[v]){
      auto [u, w] = x;
      if(dist[u] > dist[v] + w){
        dist[u] = dist[v] + w;
        pq.push({dist[u], u});
      }
    }
  }
  return dist;
}
int main(){
  int n, m, a, b, c;
  cin >> n >> m;
  vector<vector<pii>> G(n+1);
  for(int i = 0; i < m; i++){
    cin >> a >> b >> c;
    G[a].push_back({b, c});
  }
  vector<ll> ans = dijkstra(G, 1);
  for(int i = 1; i <= n; i++){
    cout << ans[i] << " ";
  }
}