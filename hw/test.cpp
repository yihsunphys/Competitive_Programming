#include <bits/stdc++.h>
using namespace std;

// bool row[9][10],col[9][10];
// bool sub[3][3][10];int grid[9][9];
// bool legal(int r, int c, int num){
//   return (!row[r][num])&&(!col[c][num])&&(!sub[r/3][c/3][num]);
// }
// void dfs(int idx){
//   if(idx==81) {
//     print();
//     return;
//   }
//   int r=idx/9,c=idx%9;
//   if(grid[r][c]) dfs(idx+1);
//   for(int i=1;i<=9;i++){
//     if(legal(r,c,i)){
//       grid[r][c]=i;
//       row[r][i]=col[c][i]=sub[r/3][c/3][i]=1;
//       if (dfs(idx+1)) return true;  
//       row[r][i]=col[c][i]=sub[r/3][c/3][i]=0;
//       grid[r][c]=0;
//     }
//   }
//   return false;
// }
// int main(){   
//   for(int i=0;i<9;i++){
//     string s;
//     cin >> s;
//     for(int j = 0; j < 9; j++){
//       if(isdigit(s[j])) {
//         int num = s[j]-'0';
//           grid[i][j] = num;
//           row[i][num] = col[j][num] = sub[i/3][j/3][num] = 1;
//       }
//       else grid[i][j]=0;
//     }
//   }
//   dfs(0);
//   return 0;
// }  
int row[9], col[9];
int grid[9][9];
int subgrids[3][3];
bool illegal(int r, int c, int num) {
return (row[r] | col[c] | subgrids[r / 3][c / 3]) & num;
}
void update(int r, int c, int num) {
row[r] ^= num;
col[c] ^= num;
subgrids[r / 3][c / 3] ^= num;
}
int lg(int x){
    switch(x){
        case 2: return 1;
        case 4: return 2;
        case 8: return 3;
        case 16: return 4;
        case 32: return 5;
        case 64: return 6;
        case 128: return 7;
        case 256: return 8;
        case 512: return 9;
    }
}
void print(){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++)  cout<<lg(grid[i][j]);
  }
}

bool dfs(int idx) {
  if (idx == 81){
    print();
    return true;
  } 
  int r = idx / 9, c = idx % 9;
  if (grid[r][c]) return dfs(idx + 1);
  for (int num = (1 << 1); num <= (1 << 9); num <<= 1) {
    if (illegal(r, c, num)) continue;
    grid[r][c] = num;
    update(r, c, num);
    if (dfs(idx + 1)) return true;
    update(r, c, num);
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
    memset(grid, 0, sizeof(grid));
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
    cout << '\n';
  }
}
// int main() {
//   for (int r = 0; r < 9; ++r) {
//     string buffer;
//     cin >> buffer;
//     for (int c = 0; c < 9; ++c) {
//       if (isdigit(buffer[c])) {
//         grid[r][c] = 1 << (buffer[c] - '0');
//         update(r, c, grid[r][c]);
//       }
//       else  grid[r][c] = 0;
//     }  
//   }
// }


