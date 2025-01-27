class Solution {
public:
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int row, col;
    int dfs(int i, int j, vector<vector<int>>& grid){
        grid[i][j] = 0;
        int tmp=1;
        for(int k = 0; k < 4; k++){
            int x = i+dx[k], y=j+dy[k];
            if(x<0||x>=row||y<0||y>=col||grid[x][y]==0)
                continue;
            tmp+=dfs(x, y, grid);
        }
        return tmp;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        int ans = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]==1) ans = max(ans, dfs(i, j, grid));
            }
        }
        return ans;
    }
};