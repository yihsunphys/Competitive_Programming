class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>& q){
        int n = grid.size();
        if(x<0 || x>=n || y<0 || y>=n || grid[x][y]!=1) return;
        q.push({x,y});
        grid[x][y] = 2;
        for(int i = 0; i < 4; i++){
            dfs(grid, x+dx[i], y+dy[i], q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int num = 0;
        queue<pair<int, int>> q;
        bool found = false;
        for(int i = 0; i < n && !found; i++){
            for(int j= 0; j < n && !found; j++){
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found = true;
                }
            }
        }
        while(!q.empty()){
            int m = q.size();
            while(m--){
                pair<int, int> cur = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = cur.first+dx[i];
                    int ny = cur.second+dy[i];
                    if(nx<0 || nx>=n || ny<0 || ny>=n || grid[nx][ny]==2) continue;
                    if (grid[nx][ny] == 1) return num;
                    else q.push({nx,ny}); 
                    grid[nx][ny] = 2;
                }
            }
            num++;
        }
        return -1;
    }
};