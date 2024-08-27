#include <bits/stdc++.h>
using namespace std;
vector<int> v[200005];
int main() {
  int n, m;
  cin >> n >> m;
  for(int i  = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y); v[y].push_back(x);
  }
  queue<int> q;
  bool visited[200005];
  int parent[200005];
  memset(visited, 0, sizeof(visited));
  memset(parent, -1, sizeof(parent));
  q.push(1);
  visited[1] = 1;
  while(!q.empty()) {
    int now = q.front(); q.pop();
    for(auto it: v[now]){
        if(visited[it] == 0){
          parent[it] = now;
          q.push(it);
          visited[it] = 1;
        }
    }
  }
  if(visited[n] == 0){
    cout << "IMPOSSIBLE\n";
  }
  else {
    vector<int> ans;
    int now = n, cnt = 1;
    while(now!=1) {
        ans.push_back(now);
        now = parent[now];
        cnt++;
    }
    ans.push_back(1);
    cout << cnt << '\n';
    for(auto it = ans.rbegin(); it != ans.rend(); ++it)
      cout << *it << " ";
  }
}