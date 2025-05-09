class Solution {
    public:
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
    
        void bfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited){
            int n = grid.size(); 
            int m = grid[0].size();
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            while(!q.empty()){
                auto[x, y] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x+dx[i], ny = y+dy[i];
                    if( nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        grid[nx][ny] == '1' && !visited[nx][ny]){
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            
        }
        int numIslands(vector<vector<char>>& grid) {
            int n = grid.size(); 
            int m = grid[0].size();
    
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            int ans = 0;
    
            for(int i= 0; i < n;i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j]=='1' && !visited[i][j]){
                        ans++;
                        bfs(grid, i, j, visited);
                    }
                }
            }
            return ans;
        }
    };