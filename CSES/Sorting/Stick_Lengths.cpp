#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i]; 
  sort(a, a+n);
  long long sum = 0;
  for(int i = 0; i < n; i++)
    sum+=abs(a[i]-a[n/2]);
  cout << sum;
}