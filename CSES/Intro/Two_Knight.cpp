#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll count(ll n) {
  ll total = (n*n)*(n*n-1)/2;
  ll attack = (n-2)*(n-1)*4;
  return total-attack;
} 

int main() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
      cout << count(i) << '\n';
}