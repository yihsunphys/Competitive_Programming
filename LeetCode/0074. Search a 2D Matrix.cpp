class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int n = matrix.size();    // 總行數 (Rows)
        int m = matrix[0].size(); // 總列數 (Cols)
        
        int l = 0, r = n * m - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            // 關鍵修正：使用 m (每列長度) 來換算座標
            int row = mid / m;
            int col = mid % m;
            
            if (matrix[row][col] == target) {
                return true; // 找到了直接回傳
            } else if (matrix[row][col] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return false;
    }
};