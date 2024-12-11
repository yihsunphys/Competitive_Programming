void build_segment_tree(L, R) {
  //把[L, R] 分成一塊
  if(L == R) return;
  int m = (L + R) / 2;
  // 左右兩邊在各自遞迴分塊
  build_segment_tree(L, m);
  build_segment_tree(m + 1, R);
}

int seg[4* MAXN];
void pull(int id) {
  seg[id] = seg[id* 2] + seg[id * 2+ 1];
}
void build(int l, int r, int id = 1) {
  if (l == r) {
    seg[id] = a[l];
    return;
  }
  int m = (l+ r) / 2;
  build(l, m, 2* id);
  build(m+ 1, r,2* id + 1);
  pull(id);
}



int query(int ql, int qr, int l, int r, int id = 1) {
  if(qr < l|| r< ql) // [l,r] 不在 [ql,qr] 的範圍
    return 0;
  if(ql <= l&& r <= qr) // [l,r] 被 [ql,qr] 完全包含
    return seg[id];
  int m= (l + r) / 2; // 剩下就遞迴處理
  return query(ql, qr, l, m, id * 2) + query(ql, qr, m+ 1, r, id* 2+ 1);
}

void update(int p, int val, int l, int r, int id= 1) {
  if(p< l|| r< p) // 範圍外
    return;
  if(l== r) { // 範圍內
    seg[id] = val;
    return;
  }
  // 分兩半
  int m = (l + r) / 2;
  update(p, val, l, m, id* 2);
  update(p, val, m+ 1, r, id * 2+ 1);
  pull(id); // 不要忘了他，待會是重點之一
}

