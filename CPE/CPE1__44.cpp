#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10005];
bool cmp(int x, int y) {
  int x_ = x%m; int y_ = y%m;
  if(x_ != y_) return x_ < y_;
  if(x%2 != y%2) return x%2 > y%2;
  if(x%2 == 0) return x < y;
  return x > y;
}
int main() {
    while(cin >> n >> m){
        if(n ==0 && m == 0){
            cout<<"0 0\n";
            break;
        }
        for(int i = 0; i < n; i++) 
          cin >> a[i];
        sort(a, a+n, cmp);
        cout << n << " " << m << '\n';
        for(int i = 0; i < n; i++) 
          cout << a[i] << '\n';
    }
}