#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
  void modify(int x, ll val) {
  for (; x <= n; x+= x&-x)
    bit[x] += val;
   }
};
class RangeBIT {
  int n;
  BIT D, xD;

public:
  void init(int _n) {
    n = _n;
    D.init(n);
    xD.init(n);
  }
  void add(int ql, int qr, ll val) { // [ql, qr] 加值
    D.modify(ql, val);
    xD.modify(ql, ql * val);
    D.modify(qr + 1, -val);
    xD.modify(qr + 1, -(qr + 1) * val);
  }
  long long query(int x) { // 查詢 [1,x] 總和
    return (x + 1) * D.query(x) - xD.query(x);
  }
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, type, a, b, u, k;
    cin >> n >> q;
    RangeBIT r;
    r.init(n+1);
    for(int i = 1; i <= n; i++){
        cin >> k;
        r.add(i, i, k);
    }
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> a >> b >> u;
            r.add(a, b, u);
        }
        else{
            cin >> k;
            cout << r.query(k)-r.query(k-1) << "\n";
        }
    }
    return 0;
}

