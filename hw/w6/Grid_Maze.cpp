// BFS加紀錄路徑
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int n, m;
char mat[1005][1005];
int dir[1005][1005];
int main(){
  memset(dir, -1, sizeof(dir));
  cin >> n >> m;
  pii start, end;
  for(int i = 0; i < n ; i++){
    for(int j = 0; j < m; j++){
      cin >> mat[i][j];
      if(mat[i][j] == 'A') start = {i, j};
      if(mat[i][j] == 'B') end = {i, j};
    }
  }
  queue<pii> q;
  q.push(start);
  while(!q.empty()){
    pii now = q.front(); q.pop();
    mat[now.first][now.second] = '#';
    for(int i = 0; i < 4; i++){
      int x = now.first + "1012"[i] - '1';
      int y = now.second + "2101"[i] - '1';
      if(x<0 || x>=n || y<0 || y>=m || mat[x][y] == '#') continue;
      mat[x][y] = '#';
      q.push({x, y});
      dir[x][y] = i; 
    }
  }
  int length = 0;
  if(dir[end.first][end.second] == -1) cout << "NO\n";
  else{
    cout << "YES\n";
    vector<char> path;
    auto now = end;
    while(now!=start){
      int i = dir[now.first][now.second];
      path.push_back("RULD"[i]);
      length++;
      now = {now.first - ("1012"[i]-'1'), now.second - ("2101"[i] - '1')};
    }
    cout << length << '\n';
    reverse(path.begin(), path.end());
    for(auto it: path)
      cout << it;
  }
}