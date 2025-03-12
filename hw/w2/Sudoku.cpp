#include <bits/stdc++.h>
using namespace std;

int row[9], col[9];
int grid[9][9];
int subgrids[3][3];
bool illegal(int r, int c, int num) {
return (row[r] | col[c] | subgrids[r / 3][c / 3]) & num;
}
bool isValidSudoku() {
    bool checkRow[9][10] = {false};
    bool checkCol[9][10] = {false};
    bool checkSub[3][3][10] = {false};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num = __lg(grid[i][j]); 
            if (num == 0) return false;  
            if (checkRow[i][num] || checkCol[j][num] || checkSub[i/3][j/3][num]) {
                return false;  
            }
            checkRow[i][num] = checkCol[j][num] = checkSub[i/3][j/3][num] = true;
        }
    }
    return true;  
}
void update(int r, int c, int num) {
row[r] ^= num;
col[c] ^= num;
subgrids[r / 3][c / 3] ^= num;
}

void print(){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++)  cout<<__lg(grid[i][j]);
  }
}
const int MASK = (1 << 10) - 2;
int lowbit(int x) { return x & -x; }
bool dfs(int idx) {
  if (idx == 81){
    if(isValidSudoku()) return true;
    return false;
  } 
  int r = idx / 9, c = idx % 9;
  if (grid[r][c]) return dfs(idx + 1);
  int S = MASK & ~(row[r] | col[c] | subgrids[r / 3][c / 3]);
  for (int num = 0; S; S ^= num) {
    num = lowbit(S);
    grid[r][c] = num;
    update(r, c, num);
    if (dfs(idx + 1)) return true;
    update(r, c, num);
    grid[r][c] = 0;
  }
  grid[r][c] = 0;
  return false;
}
int main(){
  char ch;
  while(1){
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(subgrids, 0, sizeof(subgrids));
    string s;
    cin >> s;
    int pos = 0;
    if(s == "end") break;
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        ch = s[pos]; pos++;
        if(isdigit(ch)){
          grid[i][j] = 1 << (ch - '0');
          update(i, j, grid[i][j]);
        }
        else  grid[i][j] = 0;
      }
    }
    if(!dfs(0)) cout << "No solution.";
    else print();
    cout << '\n';
  }
}