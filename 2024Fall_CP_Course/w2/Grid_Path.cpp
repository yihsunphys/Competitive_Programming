// dfs試所有方向如果char是?
// 剪枝條件: 只能向左或向右 || 只能向上或向下
// 斜對角unvisited但旁邊都visited
#include <bits/stdc++.h>
using namespace std;
#define isValid(a) (a >= 0 && a < 7 ? 1 : 0)

string s;
int vis[7][7];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int x, int y, int id) {
  if(id == s.size()) { 
    return(y == 6 && x == 0);}
  if(y == 6 && x == 0)
    return 0;
  if (vis[x][y])
    return 0;
  //紀錄周邊四格狀況
  //bool con[4] = {0};
  vector<bool> con(4, -1);
  for(int i = 0; i < 4; i++){ //下上右左
    if(isValid(x + dx[i]) && isValid(y + dy[i]))
      con[i] = vis[x + dx[i]][y + dy[i]];
  }
  // 上下不能走 只有左右走
  if (!con[0] && !con[1] && con[2] && con[3])
        return 0;
  if (con[0] && con[1] && !con[2] && !con[3])
        return 0;
  // 左下
  if (isValid(x - 1) && isValid(y + 1) && vis[x - 1][y + 1] == 1)
        if (!con[0] && !con[3])
            return 0;
  if (isValid(x - 1) && isValid(y - 1) && vis[x - 1][y - 1] == 1)
        if (!con[1] && !con[3])
            return 0;
  if (isValid(x + 1) && isValid(y + 1) && vis[x + 1][y + 1] == 1)
        if (!con[0] && !con[2])
            return 0;
  if (isValid(x + 1) && isValid(y - 1) && vis[x + 1][y - 1] == 1)
        if (!con[1] && !con[2])
            return 0;

  vis[x][y] = 1;
  int num = 0;
  if(s[id] == '?'){
    for(int i = 0; i < 4; i++) {
      if (isValid(x + dx[i]) && isValid(y + dy[i]))
        num += dfs(x + dx[i], y + dy[i], id + 1);
    }
  }
  else if (s[id] == 'R' && x + 1 < 7)
    num += dfs(x + 1, y, id + 1);
  else if (s[id] == 'L' && x - 1 >= 0)
    num += dfs(x - 1, y, id + 1);
  else if (s[id] == 'U' && y - 1 >= 0)
    num += dfs(x, y - 1, id + 1);
  else if (s[id] == 'D' && y + 1 < 7)
    num += dfs(x, y + 1, id + 1);
  vis[x][y] = 0;

  return num;
}
int main() {
  cin >> s;
  cout << dfs(0, 0, 0);
}