class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int idx = 0;
        int sum = 0;
        for(int i = n-1; i>=0; i--){
            for(int j = idx; j < m; j++){
                if(grid[i][j]<0){
                    sum += m-j;
                    idx = j;
                    break;
                } 
            }
        }
        return sum;
    }
};