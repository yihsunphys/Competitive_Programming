#include <bits/stdc++.h>
using namespace std'

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

class RangeAddBIT {
  int n;
  BIT D, xD;

public:
  void init(int _n) {
    n = _n;
    D.init(n);
    xD.init(n);
  }
  void add(int ql, int qr, int val) { // [ql, qr] 加值
    D.modify(ql, val);
    xD.modify(ql, ql * val);
    if (qr < n) {
      D.modify(qr + 1, -val);
      xD.modify(qr + 1, -(qr + 1) * val);
    }
  }
  long long query(int x) { // 查詢 [1,x] 總和
    return (x + 1) * D.query(x) - xD.query(x);
  }
};

