#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  ll count = 0;
  for(int i = 0; i < n; i++){
    int idx = lower_bound(a.begin(), a.end(), a[i]*2) - a.begin();
    count += n-idx;
  }
  cout << count << endl;
}