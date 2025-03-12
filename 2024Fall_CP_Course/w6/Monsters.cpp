#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int n, m;
char mat[1005][1005];
int dir[1005][1005];
int dx[] = {1, -1, 0, 0}; // 下, 上, 右, 左
int dy[] = {0, 0, 1, -1};

int main() {
    memset(dir, -1, sizeof(dir));
    cin >> n >> m;
    pii start;
    queue<pii> q, mq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == 'A') start = {i, j};
            if(mat[i][j] == 'M') {
                mq.push({i, j});
                mat[i][j] = '#'; // 怪物起始位置標記為障礙
            }
        }
    }
    q.push(start);
    int res = 0;
    
    while(!q.empty()) {
        // 怪物移動
        int monsterMoves = mq.size();
        for(int i = 0; i < monsterMoves; i++) {
            auto now = mq.front(); mq.pop();
            for(int j = 0; j < 4; j++) {
                int x = now.first + dx[j];
                int y = now.second + dy[j];
                if(x < 0 || x >= n || y < 0 || y >= m || mat[x][y] != '.') continue;
                mat[x][y] = '#';
                mq.push({x, y});
            }
        }

        // 玩家移動
        int playerMoves = q.size();
        for(int i = 0; i < playerMoves; i++) {
            pii now = q.front(); q.pop();
            if(now.first == 0 || now.first == n-1 || now.second == 0 || now.second == m-1) {
                cout << "YES\n" << res << '\n';
                vector<char> path;
                while(now != start) {
                    int j = dir[now.first][now.second];
                    path.push_back("DURL"[j]);
                    now = {now.first - dx[j], now.second - dy[j]};
                }
                reverse(path.begin(), path.end());
                for(auto it : path)
                    cout << it;
                return 0;
            }
            mat[now.first][now.second] = '#'; // 訪問過的位置標記
            for(int j = 0; j < 4; j++) {
                int x = now.first + dx[j];
                int y = now.second + dy[j];
                if(x < 0 || x >= n || y < 0 || y >= m || mat[x][y] == '#') continue;
                mat[x][y] = '#';
                q.push({x, y});
                dir[x][y] = j; 
            }
        }
        res++;
    }
    cout << "NO\n";
}
