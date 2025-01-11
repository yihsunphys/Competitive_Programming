#include <bits/stdc++.h>
using namespace std;
int v[100], w[100];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  int d[n+1][m+1];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= m; j++) {
        if(w[j] > m) d[i+1][j] = d[i][j];
        else
          d[i+1][j] = max(d[i][j], v[j] + d[i][j-w[j]]);
    }
  }
}
