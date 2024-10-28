#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(4));
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    b[i] = a[i][3] = a[i][0] + a[i][1] + a[i][2];
  }
  sort(b.begin(), b.end()); //cout << b[n-k];
  for(int i = 0; i <n; i++) {
    if((b[n-k] - a[i][3]) <= 300) cout << "Yes\n";
    else cout << "No\n";
  }
}