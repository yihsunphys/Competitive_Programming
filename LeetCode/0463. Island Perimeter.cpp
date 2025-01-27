class Solution {
public:
    int dx[2] = {-1, 0}; int dy[2] = {0, -1};
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){ ans+=4;
                    for(int k = 0; k < 2; k++){
                        int x = i+dx[k], y = j+dy[k];
                        if(x<0||y<0) continue;
                        if(grid[x][y]==1) ans-=2;
                    }
                }
            }
        }
        return ans;
    }
};