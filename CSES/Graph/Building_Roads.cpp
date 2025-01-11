#include <bits/stdc++.h>
using namespace std;
int n, m;
//bool road[1005][1005];
vector<int> v[100005];
bool visited[100005];
void dfs(int idx) {
  visited[idx] = 1;
  for(auto it: v[idx]) {
    if(!visited[it]) dfs(it);
  }
}
int main() {
  cin >> n >> m;
  memset(visited, 0, sizeof(visited));
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    //road[a][b] = 1; road[b][a] = 1;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int ans = 0;
  vector<int> new_road;
  for(int i = 1; i <= n; i++) {
    if(!visited[i]) {
        dfs(i);
        ans++;
        new_road.push_back(i);
    }
  }
  cout << ans-1 << '\n';
  for(int i = 0; i < new_road.size()-1; i++) {
    cout << new_road[i] << " " << new_road[i+1] << '\n';
  }
}
//dfs找連通分量