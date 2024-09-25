#include <bits/stdc++.h>
using namespace std;
#define MAXN 25
int mat[5][5];
int office[5];
int ans_office[5];
int ans = 1000000007;
//上一個放置的office位置, 放置了幾個office
void dfs(int pos, int num){
  if(num == 5){
    int sum = 0;
    for(int i  = 0; i < 25; i++){
      int tmp = 1000000007;
      for(int j = 0; j < 5; j++){
        tmp = min(tmp, mat[i/5][i%5]*(abs(office[j]/5 - i/5) + abs(office[j]%5 - i%5)));
      }
      sum += tmp;
    }
    if(sum < ans){ 
      ans = sum; 
      for(int i = 0; i < 5; i++){ 
          ans_office[i] = office[i];
      }
    }
    return;
  }
  for(int i = pos+1; i < 25; i++) {
    office[num] = i;
    dfs(i, num+1);
  }
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    memset(mat, 0, sizeof(mat));
    while(n--) {
      int row, col, num;
      cin >> row >> col >> num;
      mat[row][col] = num;
    }
    ans = 1000000007;
    dfs(-1, 0);
    for(int i = 0; i < 5; i++)
      cout << ans_office[i] << " \n"[i == 4];
  }
}