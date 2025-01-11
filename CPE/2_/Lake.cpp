#include <bits/stdc++.h>
using namespace std;
bool a[100][100];
int row, col, x, y;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int main () {
  int n;
  cin >> n;
  while(n--) {
    cin >> x >> y;
    row = 0; col = 0;
    string s;
    memset(a, 1, sizeof(a));
    getline(cin, s);
    while(getline(cin, s) && s.size()){ 
      col = s.size();
      for(int i = 0; i < s.size(); i++)
        a[row][i] = s[i]-'0';
      row++;  
    }
    
    x--; y--;
    queue<pair<int, int>> q;
    bool visit[100][100] = {};
    q.push({x, y});
    visit[x][y] = 1;
    int ans = 0;
    while(!q.empty()) {
      pair<int, int> p = q.front(); q.pop();
      ans++;
      for(int i = 0; i < 4; i++) {
        int r = p.first + dx[i];
        int c = p.second + dy[i];
        if(!a[r][c] && r >= 0 && c >= 0 && !visit[r][c]) {
          q.push({r, c});
          visit[r][c] = 1;
        }
      }
    }
    cout << ans << '\n';
  }
}
