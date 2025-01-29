class Solution {
private:
vector<vector<string>> ans;
vector<string> path;
void backtracking(int row, int n, vector<bool>& col, vector<bool>& v1, vector<bool>& v2){
    if(row == n){
        ans.emplace_back(path);
        return;
    }
    for(int i = 0; i < n; i++){
        if(col[i] || v1[row-i+n] || v2[row+i]) continue;
        string s(n, '.');
        col[i] = v1[row-i+n] = v2[row+i] = true;
        s[i] = 'Q';
        path.emplace_back(s);
        backtracking(row+1, n, col, v1, v2);
        col[i] = v1[row-i+n] = v2[row+i] = false;
        path.pop_back();
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n, false), v1(2*n, false), v2(2*n, false);
        backtracking(0, n, col, v1, v2);
        return ans;
    }
};