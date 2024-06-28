#include <bits/stdc++.h>
int w[9][9];
int d[9][9];
int next[9][9]; //紀錄路線經過的點
void floyd_warshall () {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
        d[i][j] = w[i][j];
        next[i][j] = j; 
    }
  }
  for(int i = 0; i < 9; i++)
    d[i][i] = 0;
  for(int k = 0; k < 9; k++) {
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        if(d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }
}

void path(int s, int t) {
  std::cout << s;
  if(s != t)
    path(next[s][t], t);
}