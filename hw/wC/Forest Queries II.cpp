#include <bits/stdc++.h>
using namespace std;
class BIT{
  int n;
  vector<long long> bit;
public:
    void init(int _n) {
      n = _n;
      bit.resize(n);
      for(auto &b: bit) b= 0;
    }
  long long query(int x) const{
    long long sum= 0;
    for (; x; x-= x&-x)
      sum+= bit[x];
    return sum;
  }
  void modify(int x, int val) {
  for (; x <= n; x+= x&-x)
    bit[x] += val;
   }
};

class BIT2D {
  int m;
  vector<BIT> bit1D;
public:
  void init(int _m, int _n) {
    m = _m;
    bit1D.resize(m);
    for(auto&b: bit1D) b.init(_n);
  }
  long long query(int x, int y) const{
    long long sum= 0;
    for (; x; x-= x&-x)
      sum += bit1D[x].query(y);
    return sum;
  }
  void modify(int x, int y, int val) {
    for (; x <= m; x+= x&-x)
      bit1D[x].modify(y, val);
  }
};
int main(){
  int n, q, type, x1, y1, x2, y2;
  cin >> n >> q;
  BIT2D b;
  b.init(n+1, n+1);
  vector<vector<bool>> v(n+1, vector<bool>(n+1));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      char c;
      cin >> c;
      if(c == '*') b.modify(i, j, 1), v[i][j]=1;
    }
  }
  while(q--){
    cin >> type;
    if(type == 1){
      cin >> x1 >> y1;
      if(v[x1][y1]) b.modify(x1, y1, -1);
      else b.modify(x1, y1, 1);
      v[x1][y1] = !v[x1][y1];
    }
    else{
      cin >> x1 >> y1 >> x2 >> y2;
      cout << b.query(x2, y2)-b.query(x2,y1-1)-b.query(x1-1, y2)+b.query(x1-1, y1-1) << "\n";
    }
  }
}



