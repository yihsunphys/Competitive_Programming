#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, m, n1, n2;
  int a[26];
  vector<int> v[26];
  string s1, s2;
  cin >> k;
  while(k--) {
    cin >> n >> m;
    memset(a, -1, sizeof(a));
    for(int i = 0; i < 26; i++)
      v[i].clear();
    while(n--) {
      cin >> s1 >>s2;
      n1 = s1[0] - 'A';
      n2 = s2[0] - 'A';
      a[n2] = n1; 
    }
    int cur;
    for(int i = 0; i <26; i++) {
      v[i].push_back(i);
      cur = i;
      while(a[cur] != -1) {
        v[i].push_back(a[cur]);
        cur = a[cur]; 
      }
    }
    while(m--) {
      cin >> s1 >> s2;
      n1 = s1[0] - 'A';
      n2 = s2[0] - 'A';
      int root = -1;
      for(int i : v[n1]){
        for(int j : v[n2]){
          if(i == j) {
            root = i;
            break;
          }
        }
        if(root == i) break; //因為要跳出雙重迴圈
      }
      for(int i = 0; i < v[n1].size(); i++) {
        if(v[n1][i] == root) break;
        cout << char(v[n1][i] + 'A');
      }
      bool flag = false;
      for(int i = v[n2].size()-1; i >= 0; i--) {
        if(v[n2][i] == root) flag = true;
        if(flag) cout << char(v[n2][i] + 'A'); 
      }
      cout << '\n';
    }
  }
}
