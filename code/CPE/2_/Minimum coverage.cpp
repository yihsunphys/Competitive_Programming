#include <bits/stdc++.h>
using namespace std;
pair<int, int> seg[100000];
int main() {
  int T;
  cin >> T;
  while(T--) {
    int M;
    cin >> M;
    int n = 0;
    int L, R;
    while(cin >> L >> R) {
      if(L == 0 && R == 0) break;
      seg[n] = make_pair(L, R);
      n++;
    }
    sort(seg, seg + n);
    vector <pair<int,int>> v;
    
    L = 0;
    int i = 0;
    while(L < M) {
      bool find = false;
      int idx = -1;
      int ma = 0;
      // while(i< n) {
      //   if(seg[i].first <= L) {
      //     find = true;
      //     if(seg[i].second > ma) {
      //       ma = seg[i].second;
      //       idx = i;
      //     }
      //   }
      //   else break;
      //   i++;
      // }
      while(seg[i].first <= L && i<n) {
          find = true;
          if(seg[i].second > ma) {
            ma = seg[i].second;
            idx = i;
          }
        i++;
      }
      if(find) {
        v.push_back(seg[idx]);
        L = ma;
      }
      else break;
    }
    if(L >= M){
      cout << v.size() << '\n';
      for(auto e: v) {
        cout << e.first << " " << e.second << '\n';
      }
    }
    else cout << "0\n";
    cout << '\n';
  }
}
