#include <bits/stdc++.h>
using namespace std;

// 如果兩個點在 dsa_oad 和 dsa_rail 都是同一個集合 map++
int parent_road[200005], parent_rail[200005];
int Find(int p[], int x){
  if(x == p[x])
    return x;
  return p[x] = Find(p, p[x]);
}
void Union(int p[], int x, int y){
  int r1 = Find(p, x);
  int r2 = Find(p, y);
  p[r1] = r2;
}

int main(){
  int n, r, k;
  cin >> n >> r >> k;
  // 初始化
  for(int i = 1; i <= n; i++){
    parent_road[i] = i;
    parent_rail[i] = i;
  }
  for(int i = 1; i <= r; i++){
    int u, v;
    cin >> u >> v;
    Union(parent_road, u, v);
  }
  for(int i = 1; i <= k; i++){
    int u, v;
    cin >> u >> v;
    Union(parent_rail, u, v);
  }
  // 路徑壓縮 確保同一集合root都一樣
  for(int i = 1; i <= n; i++){
    Find(parent_road, i);
    Find(parent_rail, i);
  }
  map<pair<int, int>, int> mp;
  for(int i = 1; i <= n; i++){
    mp[make_pair(parent_road[i], parent_rail[i])]++;
  }
  for(int i = 1; i <= n; i++){
    cout << mp[make_pair(parent_road[i], parent_rail[i])] << " ";
  }
}