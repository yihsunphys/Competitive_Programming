// 想法: 同一行就在同一個並查集 只需一次magic
#include <bits/stdc++.h>
using namespace std;
int p[200005];
int Find(int x){
  if(x == p[x])
    return x;
  return p[x] = Find(p[x]);
}
void Union(int x, int y){
  int r1 = Find(x);
  int r2 = Find(y);
  p[r1] = r2; 
}
int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    p[i] = i;
  for(int i = 0; i < m; i++){
    int x, y, z;
    cin >> x >> y >> z;
    Union(x, y);
  }
  unordered_set<int> myset;
  for(int i = 1; i <= n; i++){
    myset.insert(Find(i));
  }
  cout << myset.size() << '\n';
}

