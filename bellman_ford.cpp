#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Edge{
  int u, v, w;
};

vector<ll> bellman_ford(vector<Edge> E, int n, int S) {
  vector<ll> d(n, INF); 
  d[S] = 0; // 起點設 0
  auto relax = [&](Edge e) { 
    if (d[e.v] > d[e.u] + e.w) {
      d[e.v] = d[e.u] + e.w;
      return true;
    }
    return false;
  };
  for(int t = 1; t <= n; ++t) {
    bool update= false;
    for (auto &e : E)
      update|= relax(e);
    if(t == n && update) return{}; //有負環
  }
  return d;
}
