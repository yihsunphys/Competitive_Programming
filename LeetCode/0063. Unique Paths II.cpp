class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < n && !obstacleGrid[0][i]; i++) dp[0][i] = 1;
        for(int i = 0; i < m && !obstacleGrid[i][0]; i++) dp[i][0] = 1;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(!obstacleGrid[i][j])
                    dp[i][j] = (1-obstacleGrid[i-1][j])*dp[i-1][j] + (1-obstacleGrid[i][j-1])*dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};