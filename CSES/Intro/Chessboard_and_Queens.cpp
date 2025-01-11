#include <bits/stdc++.h>
using namespace std;
bool visited[3][20];
bool blocked[8][8];
int ans = 0;
void dfs(int n) {
  if(n == 8) ans++;
  for(int i = 0; i < 8; i++) {
    if(visited[0][i] == 0 && visited[1][i+n] == 0 
    && visited[2][i+8-n] == 0 && blocked[i][n] == 0){
      visited[0][i] = visited[1][i+n] = visited[2][i+8-n] = 1;
      dfs(n+1);
      visited[0][i] = visited[1][i+n] = visited[2][i+8-n] = 0;
    }
  }
}
int main() {
  memset(visited, 0, sizeof(visited));
  memset(blocked, 0, sizeof(blocked));
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++){
        char ch;
        cin >> ch;
        if(ch == '*') blocked[i][j] = 1;
    }
  dfs(0);
  cout << ans;
}