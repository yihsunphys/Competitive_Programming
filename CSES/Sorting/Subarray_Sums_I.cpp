#include <bits/stdc++.h>
using namespace std;
int a[200005];
int pre[200005];
int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    pre[i] = pre[i-1] + a[i];
  }
  int l = 1, r = 1;
  int cnt = 0;
  while(l<=n && r<=n) {
    int sum = pre[r]-pre[l-1];
    if(sum == m) {
        cnt++; l++;
    }
    else if(sum < m) r++;
    else l++;
  }
  cout << cnt;
}