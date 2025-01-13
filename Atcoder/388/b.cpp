#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, d;
  cin >> n >> d;
  vector<int> t(n), l(n);
  for(int i = 0; i < n; i++){
    cin >> t[i] >> l[i];
  }
  for(int i = 1; i <= d; i++){
    vector<int> tmp(n, 0);
    for(int j = 0; j < n; j++){
      tmp[j] = l[j]+i;
    }
    int mx = 0;
    for(int j = 0; j < n; j++){
      mx = max(mx, tmp[j]*t[j]);
    }
    cout << mx << endl;
  }
  
}