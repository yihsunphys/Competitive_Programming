#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Edge{
  int u, v, w;
};
class DSA{
  vector<int> parent;
  int Find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
  }
public:
  DSA(int n) :parent(n+1){init();}
  void init(){
    for(int i = 0; i < parent.size(); i++)
      parent[i] = i;
  }
  void Union(int x, int y){
    int r1 = Find(x);
    int r2 = Find(y);
    parent[r1] = r2;
  }
  bool Same(int x, int y){
    return Find(x) == Find(y);
  }
};

int main(){
  int n, m, a, b, c;
  cin >> n >> m;
  vector<Edge> E(m); 
  for(int i = 0; i < m; i++){
    cin >> E[i].u >> E[i].v >> E[i].w;
  }
  sort(E.begin(), E.end(), [](Edge a, Edge b){
    return a.w < b.w;
  });
  ll ans = 0;
  ll cnt = 0;
  DSA dsa(n);
  for(auto e: E){
    if(!dsa.Same(e.u, e.v)){
      dsa.Union(e.u, e.v);
      ans += e.w;
      cnt++;
    }
  }
  if(cnt < n-1) cout << "IMPOSSIBLE\n";
  else cout << ans << "\n";
}