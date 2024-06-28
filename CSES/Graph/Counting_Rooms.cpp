#include <bits/stdc++.h>
using namespace std;
char mat[1005][1005];
bool visited[1005][1005];
int n, m;
void bfs(int x, int y) {
  if(x < 0 || x >= n || y < 0 || y >= m) return;
  if(!visited[x][y]) {
    visited[x][y] = 1;
    bfs(x-1, y);
    bfs(x+1, y);
    bfs(x, y-1);
    bfs(x, y+1);
  }
}
int main() {
  cin >> n >> m;
  memset(visited, 0, sizeof(visited));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cin >> mat[i][j];
        if(mat[i][j] == '#') visited[i][j] = 1;
    }
  }
  int room = 0;
  for(int i = 0; i < n; i++){
    for (int j = 0; j < m; j++) {
        if(!visited[i][j]){
          bfs(i, j);
          room++;
        }
    }
  }
  cout << room << '\n';
}

//用bfs 第一次忘記處理超出範圍的case