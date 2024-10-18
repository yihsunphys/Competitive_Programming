#include <bits/stdc++.h>
using namespace std;
int n, m;
bool mat[1005][1005];
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
  cin >> n >> m;
  memset(mat, 0, sizeof(mat));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char a;
      cin >> a;
      if(a == '.') mat[i][j] = 1;
    }
  }
    int room = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 1) {
                mat[i][j] = 0;
                q.push({i, j});
                room++;
                while(!q.empty()) {
                    auto now = q.front(); q.pop();
                    for(int k = 0; k < 4; k++) {
                        int x = now.first + d[k][0];
                        int y = now.second + d[k][1];
                        if(x >= 0 && x < n && y >= 0 && y < m && mat[x][y]){
                            mat[x][y] = 0;
                            q.push({x, y});
                        }
                    }
                }
            }
        }
    }
    cout << room << '\n';
}