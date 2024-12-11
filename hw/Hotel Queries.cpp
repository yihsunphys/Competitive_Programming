// 基本線段樹問題
#include <bits/stdc++.h>
using namespace std;
class SegTree{
private:
    int n;
    vector<int> seg;
    void pull(int id){
        seg[id] = max(seg[id*2], seg[id*2+1]);
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
        if(qr<l || ql>r) return INT_MIN;
        if(ql<=l && qr>=r) return seg[id];
        int mid = l+(r-l)/2;
        return max(query(ql, qr, l, mid, id*2), query(ql, qr, mid+1, r, id*2+1));
    }
    void update(int p, int val, int l, int r, int id=1){
        if(p<l || p>r) return;
        if(l == r){seg[id] -= val; return;}
        int mid = l+(r-l)/2;
        update(p, val, l, mid, id*2);
        update(p, val, mid+1, r, id*2+1);
        pull(id);
    }
    int search(int k, int l, int r, int id=1){
      if(l==r) return l;
      int mid = (l+r)/2;
      if(seg[id*2] >= k) return search(k, l, mid, id*2);
      else return search(k, mid+1, r, id*2+1);
    }
};
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for(int i = 0; i < n; i++)
    cin >> v[i];
  SegTree s(n);
  s.build(0, n-1, v);
  for(int i = 0; i < m; i++){
    int x, ans;
    cin >> x;
    if(s.query(0, n-1, 0, n-1) < x) ans = 0;
    else {
      ans = s.search(x, 0, n-1, 1)+1;
      s.update(ans-1, x, 0, n-1);
    }
    cout << ans << " \n"[i==m-1];
  }
}