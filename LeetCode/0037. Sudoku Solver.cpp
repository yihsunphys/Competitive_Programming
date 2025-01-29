// 有解立刻返回 跟 找出所有解 寫法不一樣
class Solution {
public:
    bool colVisit[9][10];
    bool rowVisit[9][10];
    bool subgrid[3][3][10];
    bool backtracking(vector<vector<char>>& board, int idx){
        if(idx == 81)
            return true;
        int row = idx/9;
        int col = idx%9;
        if(board[row][col] != '.') 
            return backtracking(board, idx+1);
        for(int i = 1; i <= 9; i++){
            if(colVisit[col][i] || rowVisit[row][i] || subgrid[row/3][col/3][i]) 
                continue;
            board[row][col] = i+'0'; 
            colVisit[col][i] = rowVisit[row][i] = subgrid[row/3][col/3][i] = true;
            if(backtracking(board, idx+1)) return true;
            board[row][col] = '.';
            colVisit[col][i] = rowVisit[row][i] = subgrid[row/3][col/3][i] = false;
        } 
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    colVisit[j][num] = true;
                    rowVisit[i][num] = true;
                    subgrid[i / 3][j / 3][num] = true;
                }
            }
        }
        backtracking(board, 0);
    }
};