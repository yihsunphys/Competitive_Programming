// dp的概念 dp[h[i]] = dp[h[i]-1] + a[i]
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
    long long res = 0;
    for (; x; x-= x&-x)
      res = max(res, bit[x]);
    return res;
  }
  void modify(int x, ll val) {
  for (; x <= n; x+= x&-x)
    bit[x] = max(val, bit[x]);
   }
};

int main(){
  int n;
  cin >> n;
  BIT b; b.init(n+2);
  vector<int> H(n), A(n);
  for(auto& i : H) cin >> i;
  for(auto& i : A) cin >> i;
  for(int i = 0; i < n; i++){
    ll sum = b.query(H[i]-1)+A[i];
    b.modify(H[i], sum);
  }
  cout << b.query(n+1) << '\n';
}

