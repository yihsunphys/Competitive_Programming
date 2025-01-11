#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v(200005);
int main() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> v[i].first;
    v[i].second = 0;
  }
  v[0].first = v[0].second = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = i-1; j>=0; j--) {
        if(v[j].first < v[i].first) {
            cout << j << " ";
            v[i].second = j;
            break;
        }
        else {
            j = v[j].second+1;
        }
    }
  }
}