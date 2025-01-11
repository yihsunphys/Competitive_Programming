// single source shortest path
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define QueuePair pair<long long, int>
vector<vector<int>> G;

vector<long long> dijkstra(const vector<vector<pair<int, int>>> &G, int S) {
  int n = G.size(); // 假設點的編號為 0 ~ n-1
  vector<long long> d(n, INF);
  priority_queue<QueuePair, vector<QueuePair>, greater<QueuePair>> q;
  d[S] = 0; // 起點設 0
  q.emplace(d[S], S);
  while (q.size()) {
    auto [u_dis, u] = q.top();
    q.pop();
    if (d[u] < u_dis) continue; // 已經被其他點鬆弛過了且pop掉了
    for (auto [v, cost] : G[u]) // 鬆弛所有相鄰的點
    if (d[v] > d[u] + cost) {
      d[v] = d[u] + cost;
      q.emplace(d[v], v);
    }
  }
  return d;
}

