#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
int x[200005];
int ans = 0;
void dfs(int cur, int par) { //避免計算到上層的邊
  for(auto it: adj[cur]) {
    if(it == par) continue;
    dfs(it, cur);
    if(!x[it] && !x[cur]) {
        x[it] = 1; x[cur] = 1;
        ans++;
    }
  }
  
}
int main() {
  int n;
  cin >> n;
  int a, b;
  while(cin >> a >> b){
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  cout << ans;
}
//從底層開始計算有最佳子結構