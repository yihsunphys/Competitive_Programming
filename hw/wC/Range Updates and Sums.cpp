#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node{
  ll data, tag_add, tag_set;
};
class SegTree{
private:
    int n;
    vector<Node> seg;
    ll get_val(int l, int r, int id){
      if(seg[id].tag_set) return (r-l+1)*(seg[id].tag_add+seg[id].tag_set);
      return (r-l+1)*seg[id].tag_add + seg[id].data;
    }
    void pull(int l, int r, int id){
        int m = (l+r)/2;
        seg[id].data = get_val(l, m, id*2) + get_val(m+1, r, id*2+1);
    }
    void push(int l, int r, int id) {
      seg[id].data = get_val(l, r, id);
      if(seg[id].tag_set){
        seg[id* 2].tag_set = seg[id].tag_set;
        seg[id* 2+ 1].tag_set = seg[id].tag_set;
        seg[id*2].tag_add = seg[id*2+1].tag_add = 0;
        seg[id].tag_set = 0;
      }
      if(seg[id].tag_add){
        seg[id* 2].tag_add += seg[id].tag_add;
        seg[id* 2+ 1].tag_add += seg[id].tag_add;
        seg[id].tag_add = 0;
      }
    }
public:
    SegTree(int n): n(n), seg(4*n){}
    void build(int l, int r, vector<int>& A, int id=1){
        if(l == r){seg[id].data = A[l]; return;}
        int mid = (l+r)/2;
        build(l, mid, A, id*2);
        build(mid+1, r, A, id*2+1);
        pull(l, r, id);
    }
    ll query(int ql, int qr, int l, int r, int id=1){
        if(qr<l || ql>r) return 0;
        if(ql<=l && qr>=r) return get_val(l, r, id);
        push(l, r, id);
        int mid = (r+l)/2;
        return query(ql, qr, l, mid, id*2) + query(ql, qr, mid+1, r, id*2+1);
    }
    void update_add(int ql, int qr, int val, int l, int r, int id=1) {
      if(qr < l || r< ql) return;
      if(ql <= l && r <= qr) {seg[id].tag_add += val; return;}
      push(l, r, id);
      int m = (l + r) / 2;
      update_add(ql, qr, val, l, m, id* 2);
      update_add(ql, qr, val, m + 1, r, id* 2+ 1);
      pull(l, r, id);
    }
    void update_set(int ql, int qr, int val, int l, int r, int id=1) {
      if(qr < l || r< ql) return;
      if(ql <= l && r <= qr) {seg[id].tag_set = val; seg[id].tag_add = 0; return;}
      push(l, r, id);
      int m = (l + r) / 2;
      update_set(ql, qr, val, l, m, id* 2);
      update_set(ql, qr, val, m + 1, r, id* 2+ 1);
      pull(l, r, id);
    }
};

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  SegTree s(n);
  s.build(0, n-1, v);
  while(m--){
    int x, a, b, c;;
    cin >> x;
    if(x == 1){
      cin >> a >> b >> c;
      s.update_add(a-1, b-1, c, 0, n-1);
    }
    else if(x == 2){
      cin >> a >> b >> c;
      s.update_set(a-1, b-1, c, 0, n-1);
    }
    else {
      cin >> a >> b;
      cout << s.query(a-1, b-1, 0, n-1) << '\n';
    }
  }
}

