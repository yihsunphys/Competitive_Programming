// 簡單的並查集題目
#include <bits/stdc++.h>
using namespace std;

class DSA{
  vector<int> parent;
  int Find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
  }
public:
  DSA(int n) :parent(n+1){init();}
  void init(){
    for(int i = 0; i < parent.size(); i++)
      parent[i] = i;
  }
  void Union(int x, int y){
    int r1 = Find(x);
    int r2 = Find(y);
    parent[r1] = r2;
  }
  bool Same(int x, int y){
    return Find(x) == Find(y);
  }
};

int main(){
  int n, q, l, r;
  cin >> n >> q;
  DSA dsa(n+1);
  for(int i = 0; i < q; i++){
    cin >> l >> r;
    dsa.Union(l-1, r);
  }
  if(dsa.Same(0, n)) cout << "Yes\n";
  else cout << "No\n";
}