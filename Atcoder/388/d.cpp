// 差分陣列
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
    int increment = 0;
    vector<int> diff(n + 1, 0);
    for (int i = 0; i < n; i++) {
        increment += diff[i];
        a[i] += increment;
        if (a[i] > 0) {
            int start = i + 1;
            int end = min(n, i + a[i] + 1);
            diff[start] += 1;
            if (end <= n) diff[end] -= 1;
        }
        
        a[i] = max(0, a[i] - n + i + 1);
    }
  for(int i = 0; i < n; i++){
    cout << a[i] << " ";
  }
}