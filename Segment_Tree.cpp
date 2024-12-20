#include <bits/stdc++.h>
using namespace std;

class SegTree{
private:
    int n;
    vector<int> seg;
    void pull(int id){
        seg[id] = seg[id*2] + seg[id*2+1];
    }
public:
    SegTree(int n): n(n), seg(4*n){}
    void build(int l, int r, vector<int>& A, int id=1){
        if(l == r){seg[id] = A[l]; return;}
        int mid = l+(r-l)/2;
        build(l, mid, A, id*2);
        build(mid+1, r, A, id*2+1);
        pull(id);
    }
    int query(int ql, int qr, int l, int r, int id=1){
        if(qr<l || ql>r) return 0;
        if(ql<=l && qr>=r) return seg[id];
        int mid = l+(r-l)/2;
        return query(ql, qr, l, mid, id*2) + query(ql, qr, mid+1, r, id*2+1);
    }
    void update(int p, int val, int l, int r, int id=1){
        if(p<l || p>r) return;
        if(l == r){seg[id] = val; return;}
        int mid = l+(r-l)/2;
        update(p, val, l, mid, id*2);
        update(p, val, mid+1, r, id*2+1);
        pull(id);
    }
};
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  } 
  SegTree s(n);
  s.build(0, n-1, v);
  while(q--){
    int x, a, b;
    cin >> x >> a >> b;
    if(x == 2)  cout << s.query(a-1, b-1, 0, n-1) << '\n';
    else s.update(a-1, b, 0, n-1);
  }
}