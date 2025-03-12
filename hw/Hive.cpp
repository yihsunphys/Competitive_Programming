#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int ans = 1e9+7;
int mp[105][105] = {}, vis[105][105] = {}, deg[105][105] = {};
int dx[6] = {-1,0,1,1,0,-1};
int dy[6] = {1,2,1,-1,-2,-1};
int n,m,t;
// x是奇數時 y 從 1, 3, 5... x是偶數時 y 從 2, 4, 6...
pii f(int x,int y){
    return make_pair(x,(y-1)*2+(x&1)+(x%2==0?2:0));
}
int dijkstra(int sx, int sy, int ex, int ey){
    int dis[105][105] = {}, vis2[105][105] = {};
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[sx][sy] = mp[sx][sy];
    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
    pq.push({dis[sx][sy], {sx, sy}});
    while(!pq.empty()){
        auto [x, y] = pq.top().second;
        pq.pop();
        if(vis[x][y] or vis2[x][y]) continue;
        vis2[x][y] = 1;
        for(int i = 0; i < 6; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<1 or ny<1 or nx>n or ny>2*m) continue;
            if(vis[nx][ny] or vis2[nx][ny]) continue;
            if(dis[nx][ny]>dis[x][y]+mp[nx][ny]){
                dis[nx][ny] = dis[x][y]+mp[nx][ny];
                pq.push({dis[nx][ny], {nx, ny}});
            }
        }
    }
    return dis[ex][ey];
}
void dfs(int x, int y, int ex, int ey, int dis, int sx, int sy, int ex2, int ey2){
    if(dis > ans) return;
    if(x==ex and y==ey){
        ans = min(ans, dis+dijkstra(sx, sy, ex2, ey2));
        return;
    }
    for(int i = 0; i < 6; i++){ // 標記度數 
        int nx = x+dx[i],ny = y+dy[i];
        if(nx<1 or ny<1 or nx>n or ny>2*m) continue;
        deg[nx][ny]++;
    }
    for(int i = 0;i<6;++i){ 
        int nx = x+dx[i],ny = y+dy[i];
        if(nx<1 or ny<1 or nx>n or ny>2*m)continue;
        if(vis[nx][ny])continue;
        if(deg[nx][ny]>=2)continue; //有更短的路徑
        vis[nx][ny] = 1;
        dfs(nx, ny, ex, ey, dis+mp[nx][ny], sx, sy, ex2, ey2);
        vis[nx][ny] = 0;
    }
    for(int i = 0; i<6; ++i){
        int nx = x+dx[i],ny = y+dy[i];
        if(nx<1 or ny<1 or nx>n or ny>2*m)continue;
        deg[nx][ny]--;
    }
}
int main() {
  cin >> t;
  while(t--) {
    ans = 1e9+7;
    cin >> n >> m;
    int x[5], y[5];
    for(int i = 1; i <= 4; i++) {
      cin >> x[i] >> y[i];
      auto [nx, ny] = f(x[i], y[i]);
      x[i] = nx, y[i] = ny;
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        auto [nx, ny] = f(i, j);
        cin  >> mp[nx][ny];
      }
    }
    vis[x[1]][y[1]] = 1;
    dfs(x[1], y[1], x[2], y[2], mp[x[1]][y[1]], x[3], y[3], x[4], y[4]);
    if(ans >= 1e9+7) cout << -1 << endl;
    else cout << ans << endl;   
    vis[x[1]][y[1]] = 0;
  }
}