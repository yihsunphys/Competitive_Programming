#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  int start = 0, mx_len = 0;
  map<int, int> mp;
  for(int end = 0; end < n; end++) {
    if(mp.find(a[end]) == mp.end())
      mp[a[end]] = end;
    else {
      if(mp[a[end]]>=start)
        start = mp[a[end]]+1;
      mp[a[end]] = end;
    }
    mx_len = max(mx_len, end-start+1);
  } 
  cout << mx_len;
}