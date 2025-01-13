// 簡單BFS題目
class Solution {
public:
    int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int fresh = 0, rotten = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2){
                     rotten++;
                     q.push({i, j});
                }
            }
        }
        int step = 0;
        while(!q.empty()){
            step++;
            int sz = q.size();
            while(sz--){
                auto [x, y] = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int new_x = x+dx[i], new_y = y+dy[i];
                    if(new_x>=n||new_x<0||new_y>=m||new_y<0) continue;
                    if(grid[new_x][new_y]==1){
                        grid[new_x][new_y]=2; 
                        q.push({new_x, new_y});
                        fresh--;
                        if(fresh==0) return step;
                    }
                }
            }
        }
        if(fresh == 0) return 0;
        else return -1;
    }
};