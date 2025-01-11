#include <bits/stdc++.h>
using namespace std;
int a[200005];
vector<pair<int, int>> v;
int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    v.push_back({num, i+1});
  }
  sort(v.begin(), v.end());
  bool flag = 0;
  for(int i = 0; i < n; i++) {
    int l = i+1, r = n-1;
    while(l<r) {
      if(v[i].first+v[l].first+v[r].first == m){
        cout << v[i].second << " " << v[l].second << " " << v[r].second; 
        flag = 1;
        break;
      }
      else if(v[i].first+v[l].first+v[r].first < m){
        l++;
      }
      else {
        r--;
      }
    }
    if(flag) break;
  }
  if(flag == 0) cout << "IMPOSSIBLE";
}