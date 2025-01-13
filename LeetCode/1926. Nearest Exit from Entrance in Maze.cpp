// 基本 BFS題
#define pii pair<int, int>
class Solution {
public:
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}; 
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        pii start = make_pair(entrance[0], entrance[1]);
        queue<pair<pii, int>> q;
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        q.push({start, 0});
        visited[start.first][start.second] = true;
        
        while (!q.empty()) {
            auto [x, y] = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            // 檢查當前位置是否是出口（邊界）
            if ((x == 0 || y == 0 || x == n - 1 || y == m - 1) && !(x == entrance[0] && y == entrance[1])) {
                return steps;
            }
            
            // 檢查四個方向
            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i], new_y = y + dy[i];
                // 確保新的位置在有效範圍內，且不是牆壁且未被訪問過
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && maze[new_x][new_y] == '.' && !visited[new_x][new_y]) {
                    q.push({{new_x, new_y}, steps + 1});
                    visited[new_x][new_y] = true;
                }
            }
        }
        
        return -1; // 無法找到出口
    }
};