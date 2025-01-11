// 𝐷[𝑘][𝑢][𝑣] ： 
// 從 𝑢 點走到 𝑣 點，途中能經過的點編號都小於 𝑘
// 這種情況下的最短路徑
// D[0][u][v] = w[u][v] (u != v)
#include <bits/stdc++.h>
int w[9][9];
int d[9][9];
int next[9][9]; //紀錄路線經過的點
int n;
void floyd_warshall () {
  // 初始化
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        d[i][j] = w[i][j];
        next[i][j] = j; 
    }
    d[i][i] = 0;
  }
  // 開始計算
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }
}
// 輸出從 s 到 t 的最短路徑
void path(int s, int t) {
  std::cout << s;
  if(s != t)
    path(next[s][t], t);
}