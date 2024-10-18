#include <bits/stdc++.h>
using namespace std;

int n, m;
int mat[1005][1005];
struct state{
  pair<int,int> pos;
  int dist;
  string path;
  state(pair<int,int> pos, int dist): pos(pos), dist(dist), path("") {}
};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  pair<int, int> start, end;
  memset(mat, 0, sizeof(mat));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      char x;
      cin >> x;
      if(x == '#') mat[i][j] = -1;
      if(x == 'A') start = {i, j};
      if(x == 'B') end = {i, j};
    }
  }
  state start_state = state(start, 0);
  queue<state> q;
  mat[start.first][start.second] = -1;
  q.push(start_state);
  while(!q.empty()){
    state cur = q.front();
    q.pop();
    if(cur.pos == end){
      cout << "YES\n";
      cout << cur.dist << endl;
      cout << cur.path << endl;
      return 0;
    }
    for(int i = 0; i < 4; i++){
      int x = cur.pos.first + "1012"[i] - '1';
      int y = cur.pos.second + "2101"[i] - '1';
      if(x < 0 || x >= n || y < 0 || y >= m || mat[x][y] == -1) continue;
      mat[x][y] = -1;
      state next = state({x, y}, cur.dist + 1);
      next.path = cur.path + "RULD"[i];
      q.push(next);
      mat[x][y] = -1;
    }
  }
  cout << "NO\n";
}