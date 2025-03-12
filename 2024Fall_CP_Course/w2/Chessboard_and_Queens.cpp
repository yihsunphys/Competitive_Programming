#include <bits/stdc++.h>
using namespace std;
bool visited[3][20];
bool reserve[8][8];
int sol = 0;
void dfs(int n) {
  if(n == 8) {
    sol++; return;
  }
  for(int i = 0; i < 8; i++) {
    if(reserve[n][i]) continue;
    if(visited[0][i] == 0 && visited[1][n+i] == 0 && visited[2][n+8-i] == 0){
      visited[0][i] = visited[1][n+i] = visited[2][n+8-i] = 1;
      dfs(n+1);
      visited[0][i] = visited[1][n+i] = visited[2][n+8-i] = 0;
    }
  }
}
int main(){
  char ch;
  memset(visited, 0, sizeof(visited));
  memset(reserve, 0, sizeof(reserve));
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      cin >> ch; 
      if(ch == '*'){
        reserve[i][j] = 1;
      }
    }
  }
  dfs(0);
  cout << sol;
}