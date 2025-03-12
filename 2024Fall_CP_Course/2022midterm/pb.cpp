#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int> 
int n, m;
char mat[1005][1005];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main(){
  cin >> n >> m;
  for(int i  = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> mat[i][j];   
    }
  }
  queue<pii> q;
  int room = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(mat[i][j] == '.'){
        room++;
        q.push({i, j});
        while(!q.empty()){
          auto [x, y] = q.front(); q.pop();
          mat[x][y] = '#';
          for(int i = 0; i < 4; i++){
            int xx = x+dx[i]; int yy = y + dy[i];
            if(xx<0 || x>=n || y<0 || y>=m || mat[xx][yy]=='#') continue;
            q.push({xx, yy});
            mat[xx][yy] = '#';
          }
        }
      }
    }
  }
  cout << room << '\n';
}