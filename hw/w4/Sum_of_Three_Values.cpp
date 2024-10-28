#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;    
  vector<pair<int, int>> a(n+1); 
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }  
  sort(a.begin(), a.end());  
  for(int i = 1; i <= n; i++) {
    int l = i+1, r = n;
    while(l < r){
      int sum = a[i].first + a[l].first + a[r].first;
      if(sum == x) {
        cout << a[i].second << " " << a[l].second << " " << a[r].second << '\n';
        return 0;
      } 
      else if(sum < x) l++;
      else r--;
    } 
  }
  cout << "IMPOSSIBLE" << '\n';
}