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
  for (; x; x-= lowbit(x))
    sum+= bit[x];
    return sum;
  }
  void modify(int x, int val) {
  for (; x <= n; x+= lowbit(x))
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
    for (; x; x-= lowbit(x))
    sum += bit1D[x].query(y);
    return sum;
  }
  void modify(int x, int y, int val) {
    for (; x <= m; x+= lowbit(x))
    bit1D[x].modify(y, val);
  }
};

