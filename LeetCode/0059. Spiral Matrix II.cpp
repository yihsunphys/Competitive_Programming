class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int round = n/2;
        int id = 1;
        int len = n-1;
        int r = 0, c = 0;
        while(round--){
            for(int i = 0; i < len; i++)
                mat[r][c++] = id++;
            for(int i = 0; i < len; i++)
                mat[r++][c] = id++;
            for(int i = 0; i < len; i++)
                mat[r][c--] = id++;
            for(int i = 0; i < len; i++)
                mat[r--][c] = id++;
            r++;c++;
            len-=2;
        }
        if(n%2) mat[r][c] = id;
        return mat;
    }
};