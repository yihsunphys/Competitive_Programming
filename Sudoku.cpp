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

void print(){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++)  cout<<grid[i][j];
      cout<<endl;
  }
}

bool dfs(int idx) {
  if (idx == 81) return true;
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

int main() {
  for (int r = 0; r < 9; ++r) {
    string buffer;
    cin >> buffer;
    for (int c = 0; c < 9; ++c) {
      if (isdigit(buffer[c])) {
        grid[r][c] = 1 << (buffer[c] - '0');
        update(r, c, grid[r][c]);
      }
      else  grid[r][c] = 0;
    }  
  }
}


