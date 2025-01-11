#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fr(i, n) for (ll i = 0; i < n; i++)
int n, m;
vector<vector<int>> v(200005);
vector<int> visited(200005, 0);
int gp[200005];
bool fail = 0;
void dfs(int n, int id) {
  for(auto it: v[n]) {
    if(visited[it] == 1 && gp[it] == id) fail = 1;
    if(visited[it] == 0) {
        gp[it] = 3-id;
        visited[it] = 1;
        dfs(it, gp[it]);
    }
  }
}
int main() {
  memset(gp, 0, sizeof(gp));
  cin >> n >> m;
  while(m--) {
    int x, y;
    cin >> x >> y; 
    v[x].push_back(y); v[y].push_back(x);
  }
  fr(i, n){
    if(visited[i+1]==0) {
      dfs(i+1, 1); gp[i+1] = 1;  
    }
  }
  if(fail) cout << "IMPOSSIBLE";
  else 
    fr(i, n){
      cout << gp[i+1] << " ";
    }
}