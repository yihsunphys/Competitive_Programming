#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
  int n;
  cin >> n;
  int tmp, sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i] >> tmp;
    sum += tmp;
  }
  sort(a, a+n);
  int pre = 0;
  for(int i = 0; i < n; i++)
    pre += a[i]*(n-i);
  cout << sum-pre;
}