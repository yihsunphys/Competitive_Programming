#include <bits/stdc++.h>
using namespace std;
int n, m;
int mat[1005][1005];
int dir[1005][1005];
char dir_ch[4] = {'D', 'U', 'R', 'L'}; 
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  memset(dir, -1, sizeof(dir));
  memset(mat, 0, sizeof(mat));
  pair<int, int> start, end;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      if(ch == '#') mat[i][j] = 1;
      else mat[i][j] = 0;
      if(ch == 'A') start = {i, j};
      if(ch == 'B') end = {i, j};
    }
  }
  queue<pair<int, int>> q;
  q.push(start);
  while(!q.empty()) {
    auto now = q.front();
    q.pop();
    mat[now.first][now.second] = 1;
    if(now == end) break; //找到了就離開
    for(int i = 0; i < 4; i++) {
      int x = now.first + d[i][0];
      int y = now.second + d[i][1];
      if(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 0) {
        mat[x][y] = 1;
        q.push({x, y});
        dir[x][y] = i;
      }
    }
  }
  int length = 0;
  if(dir[end.first][end.second] == -1) cout << "NO\n";
  else {
    cout << "YES" << '\n';
    vector<char> v;
    auto now = end;
    while(now!=start) {
        int dirnum = dir[now.first][now.second];
        v.push_back(dir_ch[dirnum]);
        length++;
        now = {now.first - d[dirnum][0], now.second - d[dirnum][1]};
    }
    cout << length << '\n';
    reverse(v.begin(), v.end());
    for(auto it: v)
      cout << it;
  }
}
//bfs找最短路徑長度 
//如何記錄路徑? 每次push一個新座標進queue 紀錄是從哪個方向來
//最後印出路徑要反推 所以要用vector 然後reverse 順便算路徑長
