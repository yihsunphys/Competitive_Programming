#include <bits/stdc++.h>
int p[100];
int find(int x) {
  return p[x]<0 ? x: p[x] = find(p[x]);
}

void Union(int x, int y) {
  int g1 = find(x);
  int g2 = find(y);
  if(g1 != g2) {
    p[g1] += g2;
    p[g2] = g1;
  }
}