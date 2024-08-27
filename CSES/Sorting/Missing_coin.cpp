#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[200005];
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  ll mx_sum = 1;
  sort(a, a+n);
  for(int i = 0; i < n; i++) {
    if(a[i]>mx_sum) break;
    mx_sum+=a[i];
  } 
  cout << mx_sum;
}
